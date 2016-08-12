#pragma once

#include "AlienFX_Lib.h"
#include <vector>
#include <string>

class Device;
class Light;
class Color;

class MFX
{
public:
	MFX();
	~MFX();

	void makeLightList();
	void displayLightList();
	void globalLight(Color color);
	void globalLight(unsigned char, unsigned char, unsigned char, unsigned char);
	AlienFX* getAlienFX() { return afx; }

	std::vector<Device*> devices;

private:
	AlienFX* afx;
};

class Device
{
public:
	Device() = default;
	~Device() = default;

	unsigned int id;
	unsigned char type;
	std::string description;

	std::vector<Light*> lights;
};

class Light
{
public:
	Light() = default;
	~Light() = default;

	int id;
	std::string description;
};

class Color
{
public:
	Color(unsigned char, unsigned char, unsigned char, unsigned char);
	~Color() = default;

	PLFX_COLOR get();
	void set(unsigned char, unsigned char, unsigned char, unsigned char);

	unsigned char red;
	unsigned char blue;
	unsigned char green;
	unsigned char brightness;
	_LFX_COLOR lfx;
};