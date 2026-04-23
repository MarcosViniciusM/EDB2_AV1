#include "Timer.h"

Timer::Timer(){}

// utiliza funções modernas para preencher uma lista com números lineares não repetidos
// e depois embaralha-a
// assegura que teremos casos mais variados
void Timer::fillWithRandom(std::span<int> array){
	std::iota(array.begin(), array.end(), 1);
	
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(array.begin(), array.end(), g);
}

std::chrono::nanoseconds Timer::timedFunction(std::span<int> array){
/*
//	DEBUG
	for(int i = 0; i < array.size();i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
*/
	auto start = std::chrono::high_resolution_clock::now();
// -------------------------------------------------------------------
// heapsort
// c++ moderno já implementou a heapsort como funções em <algorithm>
// n log n nos piores e melhores casos
	/*
	std::make_heap(array.begin(), array.end());
	std::sort_heap(array.begin(), array.end());
*/
// ------------------------------------------------------------------
// selectionsort
// n² nos piores e melhores casos

	int n = array.size();

	for(int i = 0; i < n - 1; i++){
		int min_idx = i;
		for(int j = i + 1; j < n; j++){
			if(array[j] < array[min_idx]){
				min_idx = j;
			}
		}
		if(min_idx != i) std::swap(array[i], array[min_idx]);
	}

// ------------------------------------------------------------------
	auto end = std::chrono::high_resolution_clock::now();
/*
//	DEBUG
	for(int i = 0; i < array.size(); i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
*/
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}
