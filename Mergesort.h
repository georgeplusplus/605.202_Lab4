#pragma once

#include <string>
#include <sstream>


class Mergesort
{
public:
	Mergesort();
	Mergesort(int array[], int const begin, int const end);
	void mergeSort(int array[], int const begin, int const end);
	std::string getStats();
	bool debug_output = false;
	std::string getStream() {return ss.str();}
private:
	void merge(int array[], int const left, int const mid,
		int const right);

	int swapCount = 0;
	int compCount = 0;
	std::stringstream ss;
};

