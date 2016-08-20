#include "stdafx.h"
#include "Chrono.h"

void Chrono::set_time_point()
{
	start_point = clock.now();
	interval_point = clock.now();
}

__int64 Chrono::get_time_from_start()
{
	std::chrono::milliseconds time (0);
	time_point now_point = clock.now();
	time = std::chrono::duration_cast<std::chrono::milliseconds> (now_point - start_point);
	return time.count();
}

__int64 Chrono::get_interval()
{
	std::chrono::milliseconds time(0);
	time_point now_point = clock.now();
	time = std::chrono::duration_cast<std::chrono::milliseconds> (now_point - interval_point);
	interval_point = clock.now();
	return time.count();
}