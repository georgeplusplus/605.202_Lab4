#include "Quicksort.h"
#include "Mergesort.h"
#include "ArrayOperations.h"
#include "LinkedList.h"
#include "Node.h"

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
/**
 *  @version    1.0     2024-04-27
 *  @author     George Haralampopulos
 */

 /* Parse the args for a file path provided.
 *  Should ./GHaralampopulosLab4 [input path]
 */

bool areEqual(int arr1[], int arr2[], int size)
{

	// Linearly compare elements
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	// If all elements were same.
	return true;
}

std::string parse(int argc, char* argv[], int arg)
{
	if (arg < argc)
	{
		return argv[arg];
	}
	else
	{
		return "Arg. Out of bounds";
	}
}

/* Program entry point.
*/
int main(int argc, char* argv[])
{
	/*
	std::ofstream outfile("output.txt");

	std::string freq_table = parse(argc, argv, 1);
	std::cout << "Using Frequency Table Filepath = " << freq_table << std::endl;

	std::ifstream freqfile(freq_table);

	// First parse the Frequency Table values to generate the Huffman Tree.
	if (freqfile.is_open())
	{
		freqfile.close();
	}
	else
	{
		outfile << " File: " << clear_text << ". Not Found." << std::endl;
	}
	*/

	// QUICK SORT TEST AREA
	/*
	const int size = 50;
	int input[size] = {};
	int ordered[size] = {};

	ArrayOperations::populate_random_set(input, size);
	ArrayOperations::populate_ordered_set(ordered, size, false);
	ArrayOperations::print(input, size);
	Quicksort qs = Quicksort(input, 0, size-1, 0, true);
	ArrayOperations::print(input, size);
	std::cout << qs.getStats() << "\n";

	assert(areEqual(input, ordered, size));
	*/

	

	//LinkedList<LinkedList<Node<int>>> run_list;

	//Node* lista = NodeOperations::linkArray(a, 3);
	//Node* listb = NodeOperations::link_array(b, 3);
	

	Mergesort ms = Mergesort();
	return 0;
}

