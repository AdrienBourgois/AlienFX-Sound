#pragma once

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "includes\LFX2.h"
#include "includes\LFXDecl.h"

class AlienFX
{
public:
	LFX2INITIALIZE init;
	LFX2RELEASE release;
	LFX2RESET reset;
	LFX2UPDATE update;
	LFX2UPDATEDEFAULT updateDefault;
	LFX2GETNUMDEVICES getNumDevices;
	LFX2GETDEVDESC getDeviceDescription;
	LFX2GETNUMLIGHTS getNumLights;
	LFX2SETLIGHTCOL setLightColor;
	LFX2GETLIGHTCOL getLightColor;
	LFX2GETLIGHTDESC getLightDescription;
	LFX2GETLIGHTLOC getLightLocation;
	LFX2LIGHT light;
	LFX2SETLIGHTACTIONCOLOR setLightActionColor;
	LFX2SETLIGHTACTIONCOLOREX setLightActionColorEx;
	LFX2ACTIONCOLOR actionColor;
	LFX2ACTIONCOLOREX actionColorEx;
	LFX2SETTIMING setTiming;
	LFX2GETVERSION getVersion;

	HINSTANCE hLibrary;

	AlienFX();
	~AlienFX();
};