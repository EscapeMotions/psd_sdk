// psd_sdk Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include "PsdFile.h"
#include <fstream>

PSD_NAMESPACE_BEGIN

class NativeFile : public File
{
public:
	explicit NativeFile(Allocator* allocator);

	virtual ~NativeFile() override
	{
		DoClose();
	}

private:
	virtual bool DoOpenRead(const wchar_t* filename) PSD_OVERRIDE;
	virtual bool DoOpenWrite(const wchar_t* filename) PSD_OVERRIDE;
	virtual bool DoClose(void) PSD_OVERRIDE;

	virtual File::ReadOperation DoRead(void* buffer, uint32_t count, uint64_t position) PSD_OVERRIDE;
	virtual bool DoWaitForRead(File::ReadOperation& operation) PSD_OVERRIDE;

	virtual File::WriteOperation DoWrite(const void* buffer, uint32_t count, uint64_t position) PSD_OVERRIDE;
	virtual bool DoWaitForWrite(File::WriteOperation& operation) PSD_OVERRIDE;

	virtual uint64_t DoGetSize(void) const PSD_OVERRIDE;

	// Use std::fstream for cross-platform file I/O
	// mutable because DoGetSize is const but needs to modify seek position
	mutable std::fstream m_fileStream;
};

PSD_NAMESPACE_END
