#include "stdafx.h"
#include "LoadDLL.h"

AlienFX::AlienFX()
{
	std::cout << "DLL Initialisation..." << std::endl;

	hLibrary = LoadLibrary(_T(LFX_DLL_NAME));

	if (hLibrary)
	{
		init = (LFX2INITIALIZE)GetProcAddress(hLibrary, LFX_DLL_INITIALIZE);
		release = (LFX2RELEASE)GetProcAddress(hLibrary, LFX_DLL_RELEASE);
		reset = (LFX2RESET)GetProcAddress(hLibrary, LFX_DLL_RESET);
		update = (LFX2UPDATE)GetProcAddress(hLibrary, LFX_DLL_UPDATE);
		updateDefault = (LFX2UPDATEDEFAULT)GetProcAddress(hLibrary, LFX_DLL_UPDATEDEFAULT);
		getNumDevices = (LFX2GETNUMDEVICES)GetProcAddress(hLibrary, LFX_DLL_GETNUMDEVICES);
		getDeviceDescription = (LFX2GETDEVDESC)GetProcAddress(hLibrary, LFX_DLL_GETDEVDESC);
		getNumLights = (LFX2GETNUMLIGHTS)GetProcAddress(hLibrary, LFX_DLL_GETNUMLIGHTS);
		setLightColor = (LFX2SETLIGHTCOL)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTCOL);
		getLightColor = (LFX2GETLIGHTCOL)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTCOL);
		getLightDescription = (LFX2GETLIGHTDESC)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTDESC);
		getLightLocation = (LFX2GETLIGHTLOC)GetProcAddress(hLibrary, LFX_DLL_GETLIGHTLOC);
		light = (LFX2LIGHT)GetProcAddress(hLibrary, LFX_DLL_LIGHT);
		setLightActionColor = (LFX2SETLIGHTACTIONCOLOR)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTACTIONCOLOR);
		setLightActionColorEx = (LFX2SETLIGHTACTIONCOLOREX)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTACTIONCOLOREX);
		actionColor = (LFX2ACTIONCOLOR)GetProcAddress(hLibrary, LFX_DLL_ACTIONCOLOR);
		actionColorEx = (LFX2ACTIONCOLOREX)GetProcAddress(hLibrary, LFX_DLL_ACTIONCOLOREX);
		setTiming = (LFX2SETTIMING)GetProcAddress(hLibrary, LFX_DLL_SETTIMING);
		getVersion = (LFX2GETVERSION)GetProcAddress(hLibrary, LFX_DLL_GETVERSION);

		std::cout << "DLL Initialized !" << std::endl;
	}
	else
		std::cout << "Problem in initialisation of DLL !" << std::endl;
}

AlienFX::~AlienFX()
{
	release();
	FreeLibrary(hLibrary);
	std::cout << "DLL Free !" << std::endl;
}