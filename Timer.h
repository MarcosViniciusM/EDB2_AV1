#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <span>
#include <random>

class Timer{
private:
	void selectionSort(std::span<int> array);
	void heapSort(std::span<int> array);

public:
	void fillWithRandom(std::span<int> array);
	std::chrono::nanoseconds timedHeap(std::span<int> array);
	std::chrono::nanoseconds timedSelection(std::span<int> array);
};

#endif
