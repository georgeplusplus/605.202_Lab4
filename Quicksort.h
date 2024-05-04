#pragma once

#include <string>

class Quicksort
{
public:
	Quicksort(int* arr, int low, int high, int min_prt, bool use_med);
	void sort(int* arr, int low, int high);
	std::string getStats();
	
private:
	void getMedian(int* arr, int low, int high);
	void swap(int* arr, int low, int high);
	int partition(int* arr,  int up, int down);
	void insertionSort(int* arr, int low, int high);
	
	int min_partition_size = 0;
	bool use_median = false;
	int swapCount = 0;
	int compCount = 0;
};

