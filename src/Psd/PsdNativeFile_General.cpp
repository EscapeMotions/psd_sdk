// psd_sdk Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#include "PsdPch.h"
#include "PsdNativeFile_General.h"

#include "PsdAllocator.h"
#include "PsdPlatform.h"
#include "PsdMemoryUtil.h"
#include "PsdLog.h"
#include "Psdinttypes.h"

#include <filesystem>
#include <cstdint>
#include <cwchar>
#include <memory>
#include <new>
#include <limits>
#include <iostream>


PSD_NAMESPACE_BEGIN

// Structure to hold the result of a synchronous operation
struct SyncOperationResult {
	bool success;
};

NativeFile::NativeFile(Allocator* allocator)
    : File(allocator)
{
}

bool NativeFile::DoOpenRead(const wchar_t* filename)
{
	if (m_fileStream.is_open()) {
		DoClose(); // Close previous file if any
	}

	// Use std::filesystem::path for cross-platform wchar_t support (C++17)
	std::filesystem::path filePath(filename);
	m_fileStream.open(filePath, std::ios::in | std::ios::binary);

	return m_fileStream.is_open() && m_fileStream.good();
}

bool NativeFile::DoOpenWrite(const wchar_t* filename)
{
	if (m_fileStream.is_open()) {
		DoClose();
	}

	std::filesystem::path filePath(filename);
	m_fileStream.open(filePath, std::ios::out | std::ios::binary | std::ios::trunc);

	return m_fileStream.is_open() && m_fileStream.good();
}

bool NativeFile::DoClose(void)
{
	if (m_fileStream.is_open()) {
		m_fileStream.close();
		m_fileStream.clear();
		return !m_fileStream.is_open();
	}

	return true;
}

File::ReadOperation NativeFile::DoRead(void* buffer, uint32_t count, uint64_t position)
{
	SyncOperationResult* result = nullptr;
	bool success = false;

	if (m_fileStream.is_open() && buffer != nullptr) {
		// Clear potential past errors (like EOF) before seeking/reading
		m_fileStream.clear();
		m_fileStream.seekg(static_cast<std::fstream::pos_type>(position));

		if (m_fileStream.good()) {
			m_fileStream.read(static_cast<char*>(buffer), count);
			success = !m_fileStream.bad() && !m_fileStream.fail();

			// If we only read partially due to EOF, it's still considered "successful"
			// in the sense that the operation completed without critical errors.
			// The caller might need to check bytes read separately if that matters.
			// We clear EOF state so GetSize or other operations can work later.
			if (m_fileStream.eof()) {
				m_fileStream.clear(m_fileStream.rdstate() & ~std::ios::failbit); // Clear failbit if only EOF caused it
			}
		}
	}

	try {
		result = new SyncOperationResult{success};
	} catch (const std::bad_alloc&) {
		return nullptr;
	}

	return static_cast<File::ReadOperation>(result);
}

bool NativeFile::DoWaitForRead(ReadOperation& operation)
{
	if (operation == nullptr) {
		return false;
	}

	SyncOperationResult* result = static_cast<SyncOperationResult*>(operation);

	// Retrieve the success status and clean up allocated operation
	bool success = result->success;
	delete result;
	operation = nullptr;

	return success;
}

File::WriteOperation NativeFile::DoWrite(const void* buffer, uint32_t count, uint64_t position)
{
	SyncOperationResult* result = nullptr;
	bool success = false;

	if (!m_fileStream.is_open() && m_fileStream.bad()) {
		try { result = new SyncOperationResult{false}; } catch (...) { return nullptr; }
		return static_cast<WriteOperation>(result);
	}

	if (buffer == nullptr) {
		try { result = new SyncOperationResult{false}; } catch (...) { return nullptr; }
		return static_cast<WriteOperation>(result);
	}

	m_fileStream.clear(); // Clear potential past errors
	m_fileStream.seekp(static_cast<std::fstream::pos_type>(position));

	if (m_fileStream.good()) {
		m_fileStream.write(static_cast<const char*>(buffer), count);

		// write() sets failbit or badbit on error.
		success = !m_fileStream.fail() && !m_fileStream.bad();
	}

	try {
		result = new SyncOperationResult{success};
	} catch (const std::bad_alloc&) {
		return nullptr;
	}

	return static_cast<File::WriteOperation>(result);
}

bool NativeFile::DoWaitForWrite(WriteOperation& operation)
{
	if (operation == nullptr) {
		return false; // Invalid handle
	}

	SyncOperationResult* result = static_cast<SyncOperationResult*>(operation);

	// Retrieve the success status and clean up allocated operation
	bool success = result->success;
	delete result;
	operation = nullptr;

	return success;
}

uint64_t NativeFile::DoGetSize(void) const
{
	if (!m_fileStream.is_open() || !m_fileStream.good()) {
		// Don't attempt if stream isn't open or in a usable state
		return 0;
	}

	// Store current position (use tellg for input stream position)
	// Need to cast away const for tellg/seekg
	std::fstream& nonConstStream = const_cast<std::fstream&>(m_fileStream);
	nonConstStream.clear(); // Clear EOF/errors before seeking
	auto originalPos = nonConstStream.tellg();
	if (originalPos == std::fstream::pos_type(-1)) {
		return 0;
	}

	// Seek to the end of the file
	nonConstStream.seekg(0, std::ios::end);
	if (nonConstStream.fail()) {
		nonConstStream.clear();
		// Try to restore original position
		nonConstStream.seekg(originalPos);
		return 0;
	}

	// Get position at the end (which is the size)
	auto fileSizePos = nonConstStream.tellg();
	if (fileSizePos == std::fstream::pos_type(-1)) {
		nonConstStream.clear();
		// Try to restore original position
		nonConstStream.seekg(originalPos);
		return 0;
	}

	// Restore original position
	nonConstStream.seekg(originalPos);

	if (nonConstStream.fail()) {
		nonConstStream.clear();
	}

	return static_cast<uint64_t>(fileSizePos);
}

PSD_NAMESPACE_END
