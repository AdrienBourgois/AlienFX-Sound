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

		//unsigned int numDevs = 0;
		//std::cout << "Error : " << afx.getNumDevices(&numDevs) << std::endl;
		//std::cout << "Devices : " << numDevs << std::endl;

		LFX_COLOR color;
		color.red = 255;
		color.green = 255;
		color.blue = 255;
		color.brightness = 0;

		if (afx.light(LFX_ALL, LFX_RED | LFX_FULL_BRIGHTNESS) == LFX_SUCCESS)
			std::cout << "Light" << std::endl;
		if (afx.update() == LFX_SUCCESS)
			std::cout << "Update" << std::endl;

		while (1)
			if (_kbhit())
				break;
	}
	else
		std::cout << "Can't initialize AFX" << std::endl;

    return 0;
}

