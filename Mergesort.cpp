#include "Mergesort.h"
#include "ArrayOperations.h"

#include <string>
// C++ program for Merge Sort.
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
// Source: https://www.geeksforgeeks.org/merge-sort/

using namespace std;

Mergesort::Mergesort(int array[], int const begin, int const end)
{
    ss << ArrayOperations::print(array, end + 1);
    debug_output = (end - begin <= 50 ? true : false);
    mergeSort(array, begin, end);
    ss << ArrayOperations::print(array, end + 1);
}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void Mergesort::merge(int array[], int const left, int const mid,
    int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) 
    {
        compCount++;
        if (debug_output)
        {
            ss << "Compare: " << leftArray[indexOfSubArrayOne] << " index:" << indexOfSubArrayOne
                << " and " << rightArray[indexOfSubArrayTwo] << " index:" << indexOfSubArrayTwo << "\n";
        }
            
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) 
        {
            if (debug_output)
            {
                ss << "Swap: " << array[indexOfMergedArray] << " index:" << indexOfMergedArray
                    << " and " << leftArray[indexOfSubArrayOne] << " index:" << indexOfSubArrayOne << "\n";
            }
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else 
        {
            if (debug_output)
            {
                ss << "Swap: " << array[indexOfMergedArray] << " index:" << indexOfMergedArray
                    << " and " << rightArray[indexOfSubArrayTwo] << " index:" << indexOfSubArrayTwo << "\n";
            }
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        swapCount++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) 
    {
        compCount++;
        swapCount++;
        if (debug_output)
        {
            ss << "Compare: " << leftArray[indexOfSubArrayOne] << " index:" << indexOfSubArrayOne
                << " and " << rightArray[indexOfSubArrayTwo] << " index:" << indexOfSubArrayTwo << "\n";
            ss << "Swap: " << leftArray[indexOfSubArrayOne] << " index:" << indexOfSubArrayOne 
                << " and " << rightArray[indexOfSubArrayTwo] << " index:" << indexOfSubArrayTwo << "\n";
        }
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        compCount++;
        swapCount++;
        if (debug_output)
        {
            ss << "Compare: " << array[indexOfMergedArray] << " index:" << indexOfMergedArray
               << " and " << rightArray[indexOfSubArrayTwo] << " index:" << indexOfSubArrayTwo << "\n";
            ss << "Swap: " << array[indexOfMergedArray] << " index:" << indexOfMergedArray
                << " and " << rightArray[indexOfSubArrayTwo] << " index:" << indexOfSubArrayTwo << "\n";
        }
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void Mergesort::mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

std::string Mergesort::getStats()
{
    std::string output = std::to_string(swapCount) + "," + std::to_string(compCount);
    // Flush Counts
    swapCount = 0;
    compCount = 0;
    return std::string(output);
}