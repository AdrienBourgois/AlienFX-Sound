#pragma once

#include "AlienFX_Lib.h"
#include <vector>
#include <string>

class Device;
class Light;

class MFX
{
public:
	MFX();
	~MFX();

	void makeLightList();
	void displayLightList();
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