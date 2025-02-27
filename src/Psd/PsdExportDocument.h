// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <memory>
#include <vector>

#include "PsdExportColorMode.h"
#include "PsdExportMetaDataAttribute.h"
#include "PsdExportLayer.h"
#include "PsdAlphaChannel.h"


PSD_NAMESPACE_BEGIN

struct Thumbnail;

/// \ingroup Types
/// \class ExportDocument
/// \brief A struct representing a document to be exported.
struct ExportDocument
{
	static const unsigned int MAX_ATTRIBUTE_COUNT = 128u;
	static const unsigned int MAX_LAYER_COUNT = 256u;
	static const unsigned int MAX_ALPHA_CHANNEL_COUNT = 128u;

	uint32_t width;
	uint32_t height;
	uint16_t bitsPerChannel;
	exportColorMode::Enum colorMode;

	ExportMetaDataAttribute attributes[MAX_ATTRIBUTE_COUNT];
	unsigned int attributeCount;

	std::vector<std::unique_ptr<ExportLayer>> layers;
	uint16_t layerCount;

	void* mergedImageData[3u];

	float32_t horizontalResolution;
	uint16_t horizontalUnit;
	uint16_t widthUnit;
	float32_t verticalResolution;
	uint16_t verticalUnit;
	uint16_t heightUnit;

	AlphaChannel alphaChannels[MAX_ALPHA_CHANNEL_COUNT];
	uint16_t alphaChannelCount;
	void* alphaChannelData[MAX_ALPHA_CHANNEL_COUNT];

	uint8_t* iccProfile;
	uint32_t sizeOfICCProfile;

	uint8_t* exifData;
	uint32_t sizeOfExifData;

	Thumbnail* thumbnail;
};

PSD_NAMESPACE_END
