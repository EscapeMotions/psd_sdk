// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once
#include "PsdLayer.h"
#include "PsdLayerMask.h"


PSD_NAMESPACE_BEGIN
/// \ingroup Types
/// \class ExportLayer
/// \brief A struct representing a layer as exported to the Layer Mask section.
struct ExportLayer
{
	// the SDK currently supports R, G, B, A, Mask
	static const unsigned int MAX_CHANNEL_COUNT = 5u;

	int32_t top;
	int32_t left;
	int32_t bottom;
	int32_t right;
	char* name;
	uint32_t utf16NameLength;
	std::unique_ptr<uint16_t[]> utf16Name;
	std::unique_ptr<LayerMask> layerMask;

	blendMode::Enum blendMode;
	uint8_t opacity;
	uint8_t clipping;
	bool isVisible;

	void* channelData[MAX_CHANNEL_COUNT];
	uint32_t channelSize[MAX_CHANNEL_COUNT];
	uint16_t channelCompression[MAX_CHANNEL_COUNT];

    bool isTransparencyLocked;
    bool isCompositeLocked;
    bool isPositionLocked;
	bool isAllLocked;

	uint32_t type;

	uint16_t sheetColor;
};

PSD_NAMESPACE_END
