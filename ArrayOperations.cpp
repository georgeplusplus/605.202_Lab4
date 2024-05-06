#include "ArrayOperations.h"

#include <random>
#include <map>
#include <iostream>
#include <string>

namespace ArrayOperations
{
	void populate_ordered_set(int* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = i + 1;
		}	
	}

	void populate_reverse_set(int* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = size - i;
		}
	}

	void populate_random_set(int* arr, int size)
	{
		group num;
		num.dis = std::uniform_int_distribution<>(1, size);

		int i = 0;
		std::map<int, int> count = {};

		while (i < size)
		{
			arr[i] = roll_random(count, num, size);
			i++;
		}
		return;
	}

	int roll_random(std::map<int, int>& count, group& num, int size)
	{
		int rand = num.dis(gen);
		//std::cout << "Rolled: " << rand << "\n";
		if (count.find(rand) == count.end())
		{
			// Key doesnt exist, add it
			count[rand] = 1;
			return rand;
		}
		else
		{
			// Already exists

			int temp = count[rand] + 1;

			float percent = float(temp) / size;
			//std::cout << "Value : " << temp << " Percentage:" << percent << "\n";
			if (int(percent * 100) > num.percent_duplicates)
			{
				// Reroll until we get a good number.
				//std::cout << "Duplicate. Rerolling " << "\n";
				return roll_random(count, num, size);
			}
			else
			{
				count[rand] = temp;
				return rand;
			}
		}

		return -1;
	}

	std::string print(int* arr, int size)
	{
		std::string output = "";
		for (int k = 0; k < size; k++)
		{
			output+= (std::to_string(arr[k]) +  " ");
		}

		output+= "\n";

		return output;
	}


}; //end ArrayOperations