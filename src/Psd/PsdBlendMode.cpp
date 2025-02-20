// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#include "PsdPch.h"
#include "PsdBlendMode.h"

#include "PsdKey.h"


PSD_NAMESPACE_BEGIN

namespace blendMode
{
	// ---------------------------------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------------------------------
	Enum KeyToEnum(uint32_t key)
	{
		#define IMPLEMENT_CASE(a, b, c, d, value)		case util::Key<a, b, c, d>::VALUE:	return value

		switch (key)
		{
			IMPLEMENT_CASE('p', 'a', 's', 's', PASS_THROUGH);
			IMPLEMENT_CASE('n', 'o', 'r', 'm', NORMAL);
			IMPLEMENT_CASE('d', 'i', 's', 's', DISSOLVE);
			IMPLEMENT_CASE('d', 'a', 'r', 'k', DARKEN);
			IMPLEMENT_CASE('m', 'u', 'l', ' ', MULTIPLY);
			IMPLEMENT_CASE('i', 'd', 'i', 'v', COLOR_BURN);
			IMPLEMENT_CASE('l', 'b', 'r', 'n', LINEAR_BURN);
			IMPLEMENT_CASE('d', 'k', 'C', 'l', DARKER_COLOR);
			IMPLEMENT_CASE('l', 'i', 't', 'e', LIGHTEN);
			IMPLEMENT_CASE('s', 'c', 'r', 'n', SCREEN);
			IMPLEMENT_CASE('d', 'i', 'v', ' ', COLOR_DODGE);
			IMPLEMENT_CASE('l', 'd', 'd', 'g', LINEAR_DODGE);
			IMPLEMENT_CASE('l', 'g', 'C', 'l', LIGHTER_COLOR);
			IMPLEMENT_CASE('o', 'v', 'e', 'r', OVERLAY);
			IMPLEMENT_CASE('s', 'L', 'i', 't', SOFT_LIGHT);
			IMPLEMENT_CASE('h', 'L', 'i', 't', HARD_LIGHT);
			IMPLEMENT_CASE('v', 'L', 'i', 't', VIVID_LIGHT);
			IMPLEMENT_CASE('l', 'L', 'i', 't', LINEAR_LIGHT);
			IMPLEMENT_CASE('p', 'L', 'i', 't', PIN_LIGHT);
			IMPLEMENT_CASE('h', 'M', 'i', 'x', HARD_MIX);
			IMPLEMENT_CASE('d', 'i', 'f', 'f', DIFFERENCE);
			IMPLEMENT_CASE('s', 'm', 'u', 'd', EXCLUSION);
			IMPLEMENT_CASE('f', 's', 'u', 'b', SUBTRACT);
			IMPLEMENT_CASE('f', 'd', 'i', 'v', DIVIDE);
			IMPLEMENT_CASE('h', 'u', 'e', ' ', HUE);
			IMPLEMENT_CASE('s', 'a', 't', ' ', SATURATION);
			IMPLEMENT_CASE('c', 'o', 'l', 'r', COLOR);
			IMPLEMENT_CASE('l', 'u', 'm', ' ', LUMINOSITY);
			default:
				return UNKNOWN;
		};

		#undef IMPLEMENT_CASE
	}

	// ---------------------------------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------------------------------
	uint32_t EnumToKey(Enum value)
	{
	    switch (value)
	    {
	    case PASS_THROUGH: return util::Key<'p', 'a', 's', 's'>::VALUE;
	    case NORMAL: return util::Key<'n', 'o', 'r', 'm'>::VALUE;
	    case DISSOLVE: return util::Key<'d', 'i', 's', 's'>::VALUE;
	    case DARKEN: return util::Key<'d', 'a', 'r', 'k'>::VALUE;
	    case MULTIPLY: return util::Key<'m', 'u', 'l', ' '>::VALUE;
	    case COLOR_BURN: return util::Key<'i', 'd', 'i', 'v'>::VALUE;
	    case LINEAR_BURN: return util::Key<'l', 'b', 'r', 'n'>::VALUE;
	    case DARKER_COLOR: return util::Key<'d', 'k', 'C', 'l'>::VALUE;
	    case LIGHTEN: return util::Key<'l', 'i', 't', 'e'>::VALUE;
	    case SCREEN: return util::Key<'s', 'c', 'r', 'n'>::VALUE;
	    case COLOR_DODGE: return util::Key<'d', 'i', 'v', ' '>::VALUE;
	    case LINEAR_DODGE: return util::Key<'l', 'd', 'd', 'g'>::VALUE;
	    case LIGHTER_COLOR: return util::Key<'l', 'g', 'C', 'l'>::VALUE;
	    case OVERLAY: return util::Key<'o', 'v', 'e', 'r'>::VALUE;
	    case SOFT_LIGHT: return util::Key<'s', 'L', 'i', 't'>::VALUE;
	    case HARD_LIGHT: return util::Key<'h', 'L', 'i', 't'>::VALUE;
	    case VIVID_LIGHT: return util::Key<'v', 'L', 'i', 't'>::VALUE;
	    case LINEAR_LIGHT: return util::Key<'l', 'L', 'i', 't'>::VALUE;
	    case PIN_LIGHT: return util::Key<'p', 'L', 'i', 't'>::VALUE;
	    case HARD_MIX: return util::Key<'h', 'M', 'i', 'x'>::VALUE;
	    case DIFFERENCE: return util::Key<'d', 'i', 'f', 'f'>::VALUE;
	    case EXCLUSION: return util::Key<'s', 'm', 'u', 'd'>::VALUE;
	    case SUBTRACT: return util::Key<'f', 's', 'u', 'b'>::VALUE;
	    case DIVIDE: return util::Key<'f', 'd', 'i', 'v'>::VALUE;
	    case HUE: return util::Key<'h', 'u', 'e', ' '>::VALUE;
	    case SATURATION: return util::Key<'s', 'a', 't', ' '>::VALUE;
	    case COLOR: return util::Key<'c', 'o', 'l', 'r'>::VALUE;
	    case LUMINOSITY: return util::Key<'l', 'u', 'm', ' '>::VALUE;
	    default: return 0;
	    }
	}

	// ---------------------------------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------------------------------
	const char* ToString(Enum value)
	{
		#define IMPLEMENT_CASE(value)		case value:	return #value

		switch (value)
		{
			IMPLEMENT_CASE(PASS_THROUGH);
			IMPLEMENT_CASE(NORMAL);
			IMPLEMENT_CASE(DISSOLVE);
			IMPLEMENT_CASE(DARKEN);
			IMPLEMENT_CASE(MULTIPLY);
			IMPLEMENT_CASE(COLOR_BURN);
			IMPLEMENT_CASE(LINEAR_BURN);
			IMPLEMENT_CASE(DARKER_COLOR);
			IMPLEMENT_CASE(LIGHTEN);
			IMPLEMENT_CASE(SCREEN);
			IMPLEMENT_CASE(COLOR_DODGE);
			IMPLEMENT_CASE(LINEAR_DODGE);
			IMPLEMENT_CASE(LIGHTER_COLOR);
			IMPLEMENT_CASE(OVERLAY);
			IMPLEMENT_CASE(SOFT_LIGHT);
			IMPLEMENT_CASE(HARD_LIGHT);
			IMPLEMENT_CASE(VIVID_LIGHT);
			IMPLEMENT_CASE(LINEAR_LIGHT);
			IMPLEMENT_CASE(PIN_LIGHT);
			IMPLEMENT_CASE(HARD_MIX);
			IMPLEMENT_CASE(DIFFERENCE);
			IMPLEMENT_CASE(EXCLUSION);
			IMPLEMENT_CASE(SUBTRACT);
			IMPLEMENT_CASE(DIVIDE);
			IMPLEMENT_CASE(HUE);
			IMPLEMENT_CASE(SATURATION);
			IMPLEMENT_CASE(COLOR);
			IMPLEMENT_CASE(LUMINOSITY);
			IMPLEMENT_CASE(UNKNOWN);
		};

		return "Unhandled blend mode";

		#undef IMPLEMENT_CASE
	}
	// ---------------------------------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------------------------------
	const char* ToShortString(Enum value)
	{
#define IMPLEMENT_CASE(value, retValue)		case value:	return retValue

		switch (value)
		{
			IMPLEMENT_CASE(PASS_THROUGH, "pass");
			IMPLEMENT_CASE(NORMAL, "norm");
			IMPLEMENT_CASE(DISSOLVE, "diss");
			IMPLEMENT_CASE(DARKEN, "dark");
			IMPLEMENT_CASE(MULTIPLY, "mul ");
			IMPLEMENT_CASE(COLOR_BURN, "idiv");
			IMPLEMENT_CASE(LINEAR_BURN, "lbrn");
			IMPLEMENT_CASE(DARKER_COLOR, "dkCl");
			IMPLEMENT_CASE(LIGHTEN, "lite");
			IMPLEMENT_CASE(SCREEN, "scrn");
			IMPLEMENT_CASE(COLOR_DODGE, "div ");
			IMPLEMENT_CASE(LINEAR_DODGE, "lddg");
			IMPLEMENT_CASE(LIGHTER_COLOR, "lgCl");
			IMPLEMENT_CASE(OVERLAY, "over");
			IMPLEMENT_CASE(SOFT_LIGHT, "sLit");
			IMPLEMENT_CASE(HARD_LIGHT, "hLit");
			IMPLEMENT_CASE(VIVID_LIGHT, "vLit");
			IMPLEMENT_CASE(LINEAR_LIGHT, "lLit");
			IMPLEMENT_CASE(PIN_LIGHT, "pLit");
			IMPLEMENT_CASE(HARD_MIX, "hMix");
			IMPLEMENT_CASE(DIFFERENCE, "diff");
			IMPLEMENT_CASE(EXCLUSION, "smud");
			IMPLEMENT_CASE(SUBTRACT, "fsub");
			IMPLEMENT_CASE(DIVIDE, "fdiv");
			IMPLEMENT_CASE(HUE, "hue ");
			IMPLEMENT_CASE(SATURATION, "sat ");
			IMPLEMENT_CASE(COLOR, "colr");
			IMPLEMENT_CASE(LUMINOSITY, "lum ");
			IMPLEMENT_CASE(UNKNOWN, "unkn");
		};

		return "Unhandled blend mode";

#undef IMPLEMENT_CASE
	}
}

PSD_NAMESPACE_END
