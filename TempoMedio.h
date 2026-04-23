#ifndef TEMPOMEDIO_H
#define TEMPOMEDIO_H

#include <iostream>
#include <vector>
#include <chrono>

class TempoMedio {
private:
	std::vector<std::chrono::nanoseconds> durationVector;

public:
	std::chrono::nanoseconds getAverage();
	void add(std::chrono::nanoseconds time);
	int getSize();

};

#endif
