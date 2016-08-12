#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include "includes\LFX2.h"
#include "includes\LFXDecl.h"
#include "AlienFX_Lib.h"
#include "MFX.h"


int main()
{
	MFX mfx;
	AlienFX* afx = mfx.getAlienFX();
	afx->init();
	afx->reset();

	mfx.makeLightList();
	mfx.displayLightList();

	Color color(255, 0, 0, 255);
	mfx.globalLight(color);

	bool key_pressed = false;
	char key;

	while (!key_pressed)
	{	
		/*std::cout << "B : " << static_cast<unsigned int>(color.brightness) << std::endl;
		--color.brightness;
		if (color.brightness == 0)
			color.brightness = 255;
		
		mfx.globalLight(color);*/
		Sleep(1);

		if (_kbhit())
		{
			key = _getch();
			if (key == 'q')
				key_pressed = true;

			else if (key == '+' && color.brightness < 255)
			{
				++color.brightness;
				std::cout << "Brightness : " << (int)color.brightness << std::endl;
				mfx.globalLight(color);
			}
			else if (key == '-' && color.brightness > 0)
			{
				--color.brightness;
				std::cout << "Brightness : " << (int)color.brightness << std::endl;
				mfx.globalLight(color);
			}

			key = 0;
		}
	}

	Sleep(300);

	return EXIT_SUCCESS;
}

