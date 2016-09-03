#include "stdafx.h"
#include "Color.h"

Color::Color(unsigned char _red, unsigned char _blue, unsigned char _green, unsigned char _brightness)
{
	red = _red;
	blue = _blue;
	green = _green;
	brightness = _brightness;
}

PLFX_COLOR Color::get()
{
	lfx.red = red;
	lfx.green = green;
	lfx.blue = blue;
	lfx.brightness = brightness;

	return &lfx;
}

void Color::set(unsigned char _red, unsigned char _blue, unsigned char _green, unsigned char _brightness)
{
	red = _red;
	blue = _blue;
	green = _green;
	brightness = _brightness;
}

std::ostream& operator<<(std::ostream& os, const Color& color)
{
	os << "Red : " << static_cast<unsigned int>(color.red) <<
		" - Green : " << static_cast<unsigned int>(color.green) <<
		" - Blue : " << static_cast<unsigned int>(color.blue) <<
		" - Brightness : " << static_cast<unsigned int>(color.brightness);
	return os;
}