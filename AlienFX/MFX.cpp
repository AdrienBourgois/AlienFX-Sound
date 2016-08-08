#include "stdafx.h"
#include "MFX.h"
#include "AlienFX_Lib.h"

MFX::MFX()
{
	afx = new AlienFX;
}

MFX::~MFX()
{
	delete afx;
}

void MFX::makeLightList()
{
	unsigned int device_count = 0;
	afx->getNumDevices(&device_count);

	for (unsigned int i = 0; i < device_count; ++i)
	{
		Device* device = new Device;
		device->id = i;

		unsigned int light_count = 0;
		afx->getNumLights(device->id, &light_count);

		char device_description[30];
		unsigned char device_type = 0;
		afx->getDeviceDescription(device->id, device_description, 30, &device_type);
		device->description = std::string(device_description);
		device->type = device_type;

		for (unsigned int j = 0; j < light_count; ++j)
		{
			Light* light = new Light;
			light->id = j;

			char light_description[30];
			afx->getLightDescription(device->id, light->id, light_description, 30);
			light->description = std::string(light_description);
			
			device->lights.push_back(light);
		}

		devices.push_back(device);
	}
}

void MFX::displayLightList()
{
	for (unsigned int i = 0; i < devices.size(); ++i)
	{
		Device* device = devices[i];
		std::cout << "Device " << device->id << " : " << device->description << std::endl;

		for (unsigned int j = 0; j < device->lights.size(); ++j)
		{
			Light* light = device->lights[j];
			std::cout << "\t-> Light " << light->id << " : " << light->description << std::endl;
		}
	}
}