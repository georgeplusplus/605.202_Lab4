#include "ArrayOperations.h"

#include <random>
#include <map>
#include <iostream>


namespace ArrayOperations
{
	void populate_ordered_set(int* arr, int size, bool reverse)
	{
		if (reverse)
		{
			for (int i = size-1; i >= 0; i--)
			{
				arr[i] = i + 1;
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] = i + 1;
			}
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

	void print(int* arr, int size)
	{
		for (int k = 0; k < size; k++)
		{
			std::cout << arr[k] << " ";
		}

		std::cout << "\n";
	}


}; //end ArrayOperations