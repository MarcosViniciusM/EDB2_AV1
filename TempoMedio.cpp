#include "TempoMedio.h"

// tornada em própria classe apenas para tirar bloat da main
std::chrono::nanoseconds TempoMedio::getAverage(){
	std::chrono::nanoseconds total = std::chrono::nanoseconds::zero();
	for(int i = 0;  i < durationVector.size();i++){
		total += durationVector[i];
	}
	total /= durationVector.size();
	return total;
} 

// getters e etc
void TempoMedio::add(std::chrono::nanoseconds time){
	durationVector.push_back(time);
}

int TempoMedio::getSize(){
	return durationVector.size();
}
