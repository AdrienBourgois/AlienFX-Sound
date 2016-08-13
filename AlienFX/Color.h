#pragma once

#include "AlienFX_Lib.h"

enum color : int
{
	red = 0,
	green = 1,
	blue = 2,
	brightness = 3
};

class Color
{
public:
	Color(unsigned char, unsigned char, unsigned char, unsigned char);
	~Color() = default;

	PLFX_COLOR get();
	void set(unsigned char, unsigned char, unsigned char, unsigned char);

	void on() { brightness = 255; }
	void off() { brightness = 0; }

	unsigned char red;
	unsigned char blue;
	unsigned char green;
	unsigned char brightness;
	_LFX_COLOR lfx;
};