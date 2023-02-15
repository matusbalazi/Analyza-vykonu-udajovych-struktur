#pragma once
#include <chrono>
#include "structures/heap_monitor.h"

/// <summary> Meranie casu. </summary>
class TimeMeasurement
{
public:
	typedef std::chrono::nanoseconds TimerUnits;
public:
	TimeMeasurement();

	void start();
	void stop();
	void reset();

	TimerUnits elapsed();
private:
	std::chrono::high_resolution_clock clock_;
	std::chrono::high_resolution_clock::time_point timeStart_;
	TimerUnits timeSum_;

	bool started_;
};

