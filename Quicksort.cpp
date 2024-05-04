#include "Quicksort.h"
#include <iostream>


Quicksort::Quicksort(int* arr, int low, int high, int min_prt, bool use_med)
{
	min_partition_size = min_prt;
	use_median = use_med;
	sort(arr, low, high);
}

void Quicksort::insertionSort(int* arr, int low, int high)
{
	for (int i = low +1; i <= high; i++)
	{
		int j = i - 1;
		compCount++;
		if (arr[i] < arr[j])
		{
			swap(arr, i, j);
			if (j > 0)
			{
				for (j; j > 0; j--)
				{
					// Exit case
					compCount++;
					if (arr[j] >= arr[j - 1])
					{
						break;
					}
					swap(arr, j, j-1);
				}
			}
			
		}
		
	}
}

void Quicksort::sort(int* arr, int low, int high)
{
	// Do checks

	if (low == high)
	{
		//std::cout << "Only one in set. " << "\n";
		return;
	}
	else if (high - low == 1)
	{
		//std::cout << "Only two in set. Swap: " << arr[low] << " " << arr[high] << "\n";
		if (arr[low] > arr[high])
		{
			swap(arr, low, high);
		}
		return;
	}
	else if (low < high)
	{
		if (high - low + 1 <= min_partition_size)
		{
			std::cout << "Size lower than: " << min_partition_size << "\n";
			insertionSort(arr, low, high);
			return;
		}
		int new_pivot = partition(arr, low, high);
		sort(arr, low, new_pivot - 1);
		sort(arr, new_pivot + 1, high);
	}
}
// Up starts from left, down starts from right
int Quicksort::partition(int* arr, int low, int high)
{
	int i = low + 1;
	
	if (use_median)
	{
		getMedian(arr, low, high);
	}

	int pivot = low;

	for (int j = i; j <= high; j++)
	{
		compCount++;
		if (arr[j] < arr[pivot])
		{
			swap(arr, i, j);
			i++;
		}
	}
	swap(arr, low, i - 1);
	return i - 1;
}

void Quicksort::swap(int* arr, int low, int high)
{
	std::cout << "Swapping " << arr[low] << " : " << arr[high] << "\n";
	swapCount++;
	int temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

void Quicksort::getMedian(int* arr, int low,int high)
{
	// perform insertion sort on lowest, middle, and highest index
	int mid = (low + high) / 2;
	if(arr[low] > arr[mid])
		swap(arr, low, mid);
	if(arr[low] > arr[high])
		swap(arr, low, high);
	if (arr[mid] > arr[high])
		swap(arr, mid, high);

	// Put the median value in the first index
	swap(arr, low, mid);
}

std::string Quicksort::getStats()
{
	return std::string(std::to_string(swapCount) + "," + std::to_string(compCount));
}