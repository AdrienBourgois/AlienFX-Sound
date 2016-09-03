#include "stdafx.h"
#include "MFX.h"
#include "Chrono.h"
#include "Ease.h"

//int main()
//{
//	EaseManager em;
//	unsigned char test = 10;
//	unsigned int ease_test = em._add(test, (unsigned char)20, 10, &test);
//
//	while (test != 1)
//	{
//		std::cout << "Value : " << (int)test << std::endl;
//		em._update();
//	}
//
//	return EXIT_SUCCESS;
//}



int main(int argc, char** argv)
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

	Chrono chrono;
	chrono.set_time_point();

	EaseManager em;

	while (!quit)
	{
		/*std::cout << "B : " << static_cast<unsigned int>(color.brightness) << std::endl;
		--color.brightness;
		if (color.brightness == 0)
			color.brightness = 255;

		mfx.globalLight(color);*/
		//Sleep(1);

		/*if (_kbhit())
		{
			key = _getch();
			if (key == 'q')
				quit = true;

			else if (key == '+' && color.brightness < 245)
			{
				color.brightness += 10;
				std::cout << "Brightness : " << (int)color.brightness << std::endl;
				mfx.globalLight(color);
			}
			else if (key == '-' && color.brightness > 10)
			{
				color.brightness -= 10;
				std::cout << "Brightness : " << (int)color.brightness << std::endl;
				mfx.globalLight(color);
			}

			key = 0;
		}*/

		if (_kbhit())
		{
			key = _getch();
			if (key == 'q')
				quit = true;

			else if (key == 'f')
				unsigned int ease = em._add((unsigned char)255, (unsigned char)1, 10, &color.brightness);

			key = 0;
		}

		if (color.brightness > 0)
			mfx.globalLight(color);

		std::cout << color << std::endl;
		em._update();
	}

	return EXIT_SUCCESS;
}