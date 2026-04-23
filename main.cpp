#include <iostream>
#include <chrono>
#include <array>
#include "TempoMedio.h"
#include "Timer.h"

int main(int argc, char* argv[]){
	TempoMedio tempo;
	Timer timer;

	// passar tamanho do array pelo terminal
	int num = 32;
	if(argc == 2) num = std::stoi(argv[1]);
	const int iterations = 250000;

	std::vector<int> array(num);
	
	std::chrono::nanoseconds duracao = std::chrono::nanoseconds::zero();

	for(int i = 0; i < iterations; i++){
		std::cout << "running iteration " << i + 1 << std::endl;
		timer.fillWithRandom(array);
		tempo.add(timer.timedFunction(array));
	}

	duracao = tempo.getAverage();

	std::cout << num << ", " << duracao  << std::endl;

	return 0;
}
