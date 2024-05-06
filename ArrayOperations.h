#pragma once

#include <random>
#include <map>


namespace ArrayOperations
{


	struct group {
		std::uniform_int_distribution<> dis;
		int percent_duplicates = 1; // Represented in percentage
	};

	std::string print(int* arr, int size);
	int roll_random(std::map<int, int>& count, group& num, int size);
	void populate_random_set(int* arr, int size);
	void populate_ordered_set(int* arr, int size);
	void populate_reverse_set(int* arr, int size);

	static std::random_device rd;  // a seed source for the random number engine
	static std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

}; // end ArrayOperations
