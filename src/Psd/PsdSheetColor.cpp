//
// Created by Martin Halaj on 28. 2. 2025.
//

#include "PsdPch.h"
#include "PsdSheetColor.h"

PSD_NAMESPACE_BEGIN

namespace sheetColor
{
    // ---------------------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------------------
    Enum KeyToEnum(uint16_t key)
    {
        switch (key)
        {
            case 0: return NONE;
            case 1: return RED;
            case 2: return ORANGE;
            case 3: return YELLOW;
            case 4: return GREEN;
            case 5: return SEAFOAM;
            case 6: return BLUE;
            case 7: return INDIGO;
            case 8: return MAGENTA;
            case 9: return FUCHSIA;
            case 10: return VIOLET;
            case 11: return GRAY;

            default: return NONE;
        }
    }
}

PSD_NAMESPACE_END
