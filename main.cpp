#include <iostream>
#include <chrono>
#include <array>
#include "TempoMedio.h"
#include "Timer.h"

int main(int argc, char* argv[]){
	TempoMedio tempo;
	Timer timer;

	// passar tamanho do vector pelo terminal
	int num = 32;
	if(argc >= 2) num = std::stoi(argv[1]);
	std::vector<int> array(num);
	
	// passar qual função utilizar
	int func = 1;
	if(argc >= 3) func = std::stoi(argv[2]);

	std::chrono::nanoseconds duracao = std::chrono::nanoseconds::zero();
	const int iterations = 250000;
	for(int i = 0; i < iterations; i++){
		std::cout << "running iteration " << i + 1 << std::endl;
		timer.fillWithRandom(array);
		switch(func){
			case 1: tempo.add(timer.timedHeap(array)); break;
			case 2: tempo.add(timer.timedSelection(array)); break;
			default: tempo.add(timer.timedHeap(array)); break;
		}
	}

	duracao = tempo.getAverage();

	std::cout << num << ", " << duracao << ", ";

	if(func==1)std::cout << "Heapsort.";
	else if(func == 2)std::cout << "Selection Sort.";
	else std::cout << "defaulted to Heapsort.";
	std::cout << std::endl;

	return 0;
}
