#pragma once

#include "stdafx.h"

typedef std::chrono::high_resolution_clock::time_point time_point;

class Chrono
{
public:
	Chrono() = default;
	~Chrono() = default;

	void set_time_point();

	__int64 get_time_from_start();
	__int64 get_interval();

private:
	std::chrono::high_resolution_clock clock;
	time_point start_point;
	time_point interval_point;
};