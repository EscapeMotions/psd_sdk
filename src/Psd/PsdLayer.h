// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <memory>

#include "PsdFixedSizeString.h"

PSD_NAMESPACE_BEGIN
	struct Channel;
struct TransparencyMask;
struct LayerMask;
struct VectorMask;


/// \ingroup Types
/// \class Layer
/// \brief A struct representing a layer as stored in the Layer Mask Info section.
/// \sa LayerMaskSection Channel LayerMask VectorMask
struct Layer
{
	Layer* parent;							///< The layer's parent layer, if any.
	util::FixedSizeString name;				///< The ASCII name of the layer. Truncated to 31 characters in PSD files.
	uint16_t* utf16Name;					///< The UTF16 name of the layer.

	int32_t top;							///< Top coordinate of the rectangle that encloses the layer.
	int32_t left;							///< Left coordinate of the rectangle that encloses the layer.
	int32_t bottom;							///< Bottom coordinate of the rectangle that encloses the layer.
	int32_t right;							///< Right coordinate of the rectangle that encloses the layer.

	Channel* channels;						///< An array of channels, having channelCount entries.
	unsigned int channelCount;				///< The number of channels stored in the array.

	std::unique_ptr<LayerMask> layerMask;	///< The layer's user mask, if any.
	VectorMask* vectorMask;					///< The layer's vector mask, if any.

	uint32_t blendModeKey;					///< The key denoting the layer's blend mode. Can be any key described in \ref blendMode::Enum.
	uint8_t opacity;						///< The layer's opacity value, with the range [0, 255] mapped to [0%, 100%].
	uint8_t clipping;						///< The layer's clipping mode (not used yet).

	uint32_t type;							///< The layer's type. Can be any of \ref layerType::Enum.
	bool isVisible;							///< The layer's visibility.
	bool isPassThrough;						///< If the layer is a pass-through group.

    bool isCompositeLocked;             	///< If the layer has a composite locked (false by default).
    bool isTransparencyLocked;          	///< If the layer has a transparency locked (false by default).
    bool isPositionLocked;              	///< If the layer has a position locked (false by default).

	uint16_t sheetColorKey;					///< The layer's sheet color key. It is shown in layer browser.

	bool hasGradientFill;					///< If the layer has adjustment layer GradientFill
	bool hasBrightnessContrast;				///< If the layer has adjustment layer Brightness/Contrast
	uint32_t brightness;					///< The layer's brightness from adjustment layer.
	uint32_t contrast;						///< The layer's contrast from adjustment layer.
};

PSD_NAMESPACE_END
