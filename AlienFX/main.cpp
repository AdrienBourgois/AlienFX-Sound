#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include "includes\LFX2.h"
#include "includes\LFXDecl.h"
#include "AlienFX.h"


int main()
{
	std::cout << "Test" << std::endl;

	AlienFX afx;
	if (afx.init() == LFX_SUCCESS)
	{
		unsigned int devices_count = 0;
		std::vector<unsigned int> lights_count;

		LFX_COLOR color;
		color.red = 0;
		color.green = 255;
		color.blue = 0;
		color.brightness = 255;

		afx.reset();
		std::cout << "Reset" << std::endl;
		
		afx.getNumDevices(&devices_count);
		std::cout << "Devices : " << devices_count << std::endl;

		for (unsigned int devices_index = 0; devices_index < devices_count; devices_index++)
		{
			unsigned int count = 0;
			afx.getNumLights(devices_index, &count);
			lights_count.push_back(count);
			std::cout << "Device " << devices_index << " : " << count << " Lights " << std::endl;
		}

		bool skip = false;

		while (!skip)
		{
			for (color.brightness = 255; color.brightness > 0; color.brightness--)
			{
				for (unsigned int devices_index = 0; devices_index < devices_count; devices_index++)
				{
					for (unsigned int light_index = 0; light_index < lights_count[devices_index]; light_index++)
					{
						LFX_RESULT result = afx.setLightColor(devices_index, light_index, &color);
						//std::cout << "Device : " << devices_index << " - Light : " << light_index << std::endl;
					}
				}

				afx.update();
				std::cout << (unsigned int)color.brightness << std::endl;
				Sleep(2);
			}

			bool key_pressed = false;
			while (!key_pressed)
			{
				if (_kbhit())
				{
					char key = _getch();
					if (key == 'r')
						key_pressed = true;
					else if (key == 'q')
					{
						key_pressed = true;
						skip = true;
					}

				}
			}
		}

		afx.release();
	}
	else
		std::cout << "Can't initialize AFX" << std::endl;

    return 0;
}

