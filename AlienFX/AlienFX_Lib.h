#pragma once

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "includes\LFX2.h"
#include "includes\LFXDecl.h"

class AlienFX
{
public:
	LFX2INITIALIZE p_init;
	LFX2RELEASE p_release;
	LFX2RESET p_reset;
	LFX2UPDATE p_update;
	LFX2UPDATEDEFAULT p_updateDefault;
	LFX2GETNUMDEVICES p_getNumDevices;
	LFX2GETDEVDESC p_getDeviceDescription;
	LFX2GETNUMLIGHTS p_getNumLights;
	LFX2SETLIGHTCOL p_setLightColor;
	LFX2GETLIGHTCOL p_getLightColor;
	LFX2GETLIGHTDESC p_getLightDescription;
	LFX2GETLIGHTLOC p_getLightLocation;
	LFX2LIGHT p_light;
	LFX2SETLIGHTACTIONCOLOR p_setLightActionColor;
	LFX2SETLIGHTACTIONCOLOREX p_setLightActionColorEx;
	LFX2ACTIONCOLOR p_actionColor;
	LFX2ACTIONCOLOREX p_actionColorEx;
	LFX2SETTIMING p_setTiming;
	LFX2GETVERSION p_getVersion;

	HINSTANCE hLibrary;

	AlienFX();
	~AlienFX();

	bool init();
	bool release();
	bool reset();
	bool update();
	bool updateDefault();
	bool getNumDevices(unsigned int* const);
	bool getDeviceDescription(const unsigned int, char* const, const unsigned int, unsigned char* const);
	bool getNumLights(const unsigned int, unsigned int* const);
	bool getLightDescription(const unsigned int, const unsigned int, char* const, const unsigned int);
	bool getLightLocation(const unsigned int, const unsigned int, PLFX_POSITION const);
	bool getLightColor(const unsigned int, const unsigned int, PLFX_COLOR const);
	bool setLightColor(const unsigned int, const unsigned int, const PLFX_COLOR);
	bool light(const unsigned int, const unsigned int);
	bool setLightActionColor(const unsigned int, const unsigned int, const unsigned int, const PLFX_COLOR);
	bool setLightActionColorEx(const unsigned int, const unsigned int, const unsigned int, const PLFX_COLOR, const PLFX_COLOR);
	bool actionColor(const unsigned int, const unsigned int, const unsigned int);
	bool actionColorEx(const unsigned int, const unsigned int, const unsigned int, const unsigned int);
	bool setTiming(const int);
	bool getVersion(char* const, const unsigned int);
};