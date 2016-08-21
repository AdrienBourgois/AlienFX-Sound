#include "stdafx.h"
#include "MFX.h"
#include "Chrono.h"

int main()
{
	MFX mfx;
	AlienFX* afx = mfx.getAlienFX();
	if (afx == nullptr)
		return EXIT_FAILURE;

	mfx.makeLightList();
	mfx.displayLightList();

	Color color(255, 0, 0, 255);
	mfx.globalLight(color);

	bool quit = false;
	char key;

	while (!quit)
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
				quit = true;

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

	return EXIT_SUCCESS;
}

