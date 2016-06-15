#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "includes\LFX2.h"
#include "includes\LFXDecl.h"
#include "LoadDLL.h"


int main()
{
	std::cout << "Test" << std::endl;

	AlienFX afx;
	if (afx.init() == LFX_SUCCESS)
	{
		//char version[50];
		//afx.getVersion(version, 50);
		//std::cout << "Version : " << version << std::endl;

		afx.reset();
		std::cout << "Reset" << std::endl;

		unsigned int numDevs = 0;
		std::cout << "Error : " << afx.getNumDevices(&numDevs) << std::endl;
		std::cout << "Devices : " << numDevs << std::endl;

		LFX_COLOR color;
		color.red = 0;
		color.green = 255;
		color.blue = 0;
		color.brightness = 255;

		//if (afx.light(LFX_ALL, LFX_RED | LFX_FULL_BRIGHTNESS) == LFX_SUCCESS)
			//std::cout << "Light" << std::endl;

		while (color.brightness > 0)
		{
			for (unsigned int devIndex = 0; devIndex < numDevs; devIndex++)
			{
				unsigned int numLights = 0;
				afx.getNumLights(devIndex, &numLights);

				for (unsigned int lightIndex = 0; lightIndex < numLights; lightIndex++)
				{
					//std::cout << "Device : " << devIndex << " - Light " << lightIndex << std::endl;
					LFX_RESULT result = afx.setLightColor(devIndex, lightIndex, &color);
					//if (result == LFX_SUCCESS)
						//std::cout << "Light" << std::endl;
					//else
						//std::cout << "Light Error : " << result << std::endl;
				}
			}

			afx.update() == LFX_SUCCESS
			//if (afx.update() == LFX_SUCCESS)
				//std::cout << "Update" << std::endl;
			
			color.brightness--;
		}

		

		while (1)
			if (_kbhit())
				break;
	}
	else
		std::cout << "Can't initialize AFX" << std::endl;

    return 0;
}

