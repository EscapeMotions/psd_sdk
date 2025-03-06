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
            case 5: return BLUE;
            case 6: return VIOLET;
            case 7: return GRAY;

            default: return UNKNOWN;
        }
    }
}

PSD_NAMESPACE_END
