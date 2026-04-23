#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <span>
#include <random>

class Timer{
public:
	Timer();
	void fillWithRandom(std::span<int> array);
	std::chrono::nanoseconds timedFunction(std::span<int> array);
};

#endif
