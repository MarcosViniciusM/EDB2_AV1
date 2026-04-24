#include "Timer.h"

// utiliza funções modernas para preencher uma lista com números lineares não repetidos
// e depois embaralha-a
// assegura que teremos casos mais variados
void Timer::fillWithRandom(std::span<int> array){
	std::iota(array.begin(), array.end(), 1);
	
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(array.begin(), array.end(), g);
}

std::chrono::nanoseconds Timer::timedHeap(std::span<int> array){
	auto start = std::chrono::high_resolution_clock::now();
	heapSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}

std::chrono::nanoseconds Timer::timedSelection(std::span<int> array){
	auto start = std::chrono::high_resolution_clock::now();
	selectionSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}

void Timer::heapSort(std::span<int> array){
	std::make_heap(array.begin(), array.end());
	std::sort_heap(array.begin(), array.end());
}

void Timer::selectionSort(std::span<int> array){
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
}
