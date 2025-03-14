//
// Created by Martin Halaj on 28. 2. 2025.
//
#pragma once

PSD_NAMESPACE_BEGIN

/// \ingroup Types
/// \namespace sheetColor
/// \brief A namespace holding sheet colors.
namespace sheetColor
{
    enum Enum
    {
        NONE,
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        SEAFOAM,
        BLUE,
        INDIGO,
        MAGENTA,
        FUCHSIA,
        VIOLET,
        GRAY
    };

    /// Converts a given \a key to the corresponding \ref sheetColor::Enum.
    Enum KeyToEnum(uint16_t key);

}

PSD_NAMESPACE_END