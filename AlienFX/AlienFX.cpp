#include "stdafx.h"
#include "AlienFX.h"

AlienFX::AlienFX()
{
	std::cout << "DLL Initialisation..." << std::endl;

	hLibrary = LoadLibrary(_T(LFX_DLL_NAME));

	if (hLibrary)
	{
		p_init = (LFX2INITIALIZE)GetProcAddress(hLibrary, LFX_DLL_INITIALIZE);
		p_release = (LFX2RELEASE)GetProcAddress(hLibrary, LFX_DLL_RELEASE);
		p_reset = (LFX2RESET)GetProcAddress(hLibrary, LFX_DLL_RESET);
		p_update = (LFX2UPDATE)GetProcAddress(hLibrary, LFX_DLL_UPDATE);
		p_updateDefault = (LFX2UPDATEDEFAULT)GetProcAddress(hLibrary, LFX_DLL_UPDATEDEFAULT);
		p_getNumDevices = (LFX2GETNUMDEVICES)GetProcAddress(hLibrary, LFX_DLL_GETNUMDEVICES);
		p_getDeviceDescription = (LFX2GETDEVDESC)GetProcAddress(hLibrary, LFX_DLL_GETDEVDESC);
		p_getNumLights = (LFX2GETNUMLIGHTS)GetProcAddress(hLibrary, LFX_DLL_GETNUMLIGHTS);
		p_setLightColor = (LFX2SETLIGHTCOL)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTCOL);
		p_getLightColor = (LFX2GETLIGHTCOL)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTCOL);
		p_getLightDescription = (LFX2GETLIGHTDESC)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTDESC);
		p_getLightLocation = (LFX2GETLIGHTLOC)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTLOC);
		p_light = (LFX2LIGHT)GetProcAddress(hLibrary, LFX_DLL_LIGHT);
		p_setLightActionColor = (LFX2SETLIGHTACTIONCOLOR)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTACTIONCOLOR);
		p_setLightActionColorEx = (LFX2SETLIGHTACTIONCOLOREX)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTACTIONCOLOREX);
		p_actionColor = (LFX2ACTIONCOLOR)GetProcAddress(hLibrary, LFX_DLL_ACTIONCOLOR);
		p_actionColorEx = (LFX2ACTIONCOLOREX)GetProcAddress(hLibrary, LFX_DLL_ACTIONCOLOREX);
		p_setTiming = (LFX2SETTIMING)GetProcAddress(hLibrary, LFX_DLL_SETTIMING);
		p_getVersion = (LFX2GETVERSION)GetProcAddress(hLibrary, LFX_DLL_GETVERSION);

		std::cout << "DLL Loaded !" << std::endl;
	}
	else
		std::cout << "Problem when loading DLL !" << std::endl;
}

AlienFX::~AlienFX()
{
	release();
	FreeLibrary(hLibrary);
	std::cout << "DLL Free !" << std::endl;
}

bool AlienFX::init()
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_init();
	if (error != LFX_SUCCESS)
	{
		std::cout << "init() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::release()
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_release();
	if (error != LFX_SUCCESS)
	{
		std::cout << "release() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::reset()
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_reset();
	if (error != LFX_SUCCESS)
	{
		std::cout << "reset() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::update()
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_update();
	if (error != LFX_SUCCESS)
	{
		std::cout << "update() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::updateDefault()
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_updateDefault();
	if (error != LFX_SUCCESS)
	{
		std::cout << "updateDefault() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::getNumDevices(unsigned int* const p_num)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_getNumDevices(p_num);
	if (error != LFX_SUCCESS)
	{
		std::cout << "getNumDevices() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::getDeviceDescription(const unsigned int device_index, char* const array_desc, const unsigned int size_desc, unsigned char* const device_type)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_getDeviceDescription(device_index, array_desc, size_desc, device_type);
	if (error != LFX_SUCCESS)
	{
		std::cout << "getDeviceDescription() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::getNumLights(const unsigned int device_index, unsigned int* const device_count)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_getNumLights(device_index, device_count);
	if (error != LFX_SUCCESS)
	{
		std::cout << "getNumLights() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::setLightColor(const unsigned int device_index, const unsigned int light_index, const PLFX_COLOR color)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_setLightColor(device_index, light_index, color);
	if (error != LFX_SUCCESS)
	{
		std::cout << "setLightColor() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::getLightColor(const unsigned int device_index, const unsigned int light_index, PLFX_COLOR const color)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_getLightColor(device_index, light_index, color);
	if (error != LFX_SUCCESS)
	{
		std::cout << "getLightColor() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::getLightDescription(const unsigned int device_index, const unsigned int light_index, char* const desc_array, const unsigned int size_array)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_getLightDescription(device_index, light_index, desc_array, size_array);
	if (error != LFX_SUCCESS)
	{
		std::cout << "getLightDescription() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::getLightLocation(const unsigned int device_index, const unsigned int light_index, PLFX_POSITION const location)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_getLightLocation(device_index, light_index, location);
	if (error != LFX_SUCCESS)
	{
		std::cout << "getLightLocation() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::light(const unsigned int location_mask, const unsigned int packed_color)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_light(location_mask, packed_color);
	if (error != LFX_SUCCESS)
	{
		std::cout << "light() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::setLightActionColor(const unsigned int device_index, const unsigned int light_index, const unsigned int action_type, const PLFX_COLOR color)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_setLightActionColor(device_index, light_index, action_type, color);
	if (error != LFX_SUCCESS)
	{
		std::cout << "setLightActionColor() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::setLightActionColorEx(const unsigned int device_index, const unsigned int light_index, const unsigned int action_type, const PLFX_COLOR primary_color, const PLFX_COLOR secondary_color)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_setLightActionColorEx(device_index, light_index, action_type, primary_color, secondary_color);
	if (error != LFX_SUCCESS)
	{
		std::cout << "setLightActionColorEx() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::actionColor(const unsigned int location_mask, const unsigned int action_type, const unsigned int packed_color)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_actionColor(location_mask, action_type, packed_color);
	if (error != LFX_SUCCESS)
	{
		std::cout << "actionColor() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::actionColorEx(const unsigned int location_mask, const unsigned int action_type, const unsigned int primary_packed_color, const unsigned int secondary_packed_color)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_actionColorEx(location_mask, action_type, primary_packed_color, secondary_packed_color);
	if (error != LFX_SUCCESS)
	{
		std::cout << "actionColorEx() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::setTiming(const int timing)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_setTiming(timing);
	if (error != LFX_SUCCESS)
	{
		std::cout << "setTiming() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}

bool AlienFX::getVersion(char* const version_array, const unsigned int size_array)
{
	LFX_RESULT error = LFX_FAILURE;
	error = p_getVersion(version_array, size_array);
	if (error != LFX_SUCCESS)
	{
		std::cout << "getVersion() : Error -> " << error << std::endl;
		return false;
	}
	return true;
}