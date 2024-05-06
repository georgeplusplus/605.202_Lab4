#include "Quicksort.h"
#include "Mergesort.h"
#include "ArrayOperations.h"
#include "Node.h"
#include "argparse.hpp"

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>
#include <filesystem>
#include <system_error>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
/**
 *  @version    1.0     2024-04-27
 *  @author     George Haralampopulos
 */

 /* Parse the args for a file path provided.
 *  Refer to readme for running 
 */

void generateInputFiles(const std::vector<int>& sizes, const std::string& dir);
void parseInputFiles(const std::filesystem::path& path);
bool areEqual(int arr1[], int arr2[], int size);

void generateInputFiles(const std::vector<int> &sizes, const std::string& dir)
{
	std::string input_dir = dir + "\\input\\";
	if (!std::filesystem::exists(input_dir))
	{
		std::filesystem::create_directory(input_dir);
	}
	std::vector<std::string> file_types = { "ran", "ord", "rev" };
	for (auto& size : sizes)
	{
		std::string output_footer = std::to_string(size) + ".dat";
		for (auto& ft : file_types)
		{
			
			std::cout << "Generating File: " << input_dir + ft + output_footer << "\n";
			std::ofstream outfile(input_dir + ft + output_footer);
			int* temp = new int[size];
			if (ft == "ran")
				ArrayOperations::populate_random_set(temp, size);
			else if (ft == "ord")
				ArrayOperations::populate_ordered_set(temp, size);
			else if (ft == "rev")
				ArrayOperations::populate_reverse_set(temp, size);
			else
				throw std::out_of_range("Unknown File Type encountered when generating files.");

			for (int j = 0; j < size; j++) 
			{
				outfile << temp[j] << " ";
			}
			outfile.close();
			delete[] temp;
		}
	}
}

void parseInputFiles(const std::filesystem::path &path, std::ofstream &output_metrics_file)
{
	std::cout << path << std::endl;
	int size = std::stoi(path.filename().string().substr(3));
	int* arr = new int[size];
	std::ifstream input_stream(path);
	if (!input_stream)
	{
		delete[] arr;
		throw std::runtime_error("Could not open file: " + path.string());
	}

	// Parse Input File into Array
	int line;
	int i = 0;
	input_stream >> line;
	while (!input_stream.eof())
	{

		if (i < size)
		{
			arr[i] = line;
			i++;
		}
		else
		{
			// We should never be here. Size was not loaded correctly.
			delete[] arr;
			throw std::runtime_error("Index out of bounds " + i);

		}
		input_stream >> line;
	}

	input_stream.close();

	int* temp = new int[size];

	std::string output_file_prefix = path.parent_path().parent_path().string() + "\\output\\" + path.filename().string();

	// Make copy of main array so we can run multiple sorts against it
	std::memcpy(temp, arr, sizeof(int) * size);
	assert(areEqual(arr, temp, size));

	// Merge Sort 
	Mergesort ms = Mergesort(temp, 0, size - 1);
	
	std::ofstream mergesort_stream(output_file_prefix + "_MergeSort.txt");
	mergesort_stream << ms.getStream();
	mergesort_stream.close();

	output_metrics_file << "MergeSort" << "," << path.filename().string() << "," << size << "," << ms.getStats() << "\n";


	std::memcpy(temp, arr, sizeof(int) * size);
	assert(areEqual(arr, temp, size));

	//
	// Quicksort - First Item as Pivot - Min Partition 1
	//
	Quicksort qs = Quicksort(temp, 0, size - 1, 0, false);

	std::ofstream qs1_stream(output_file_prefix + "_Quicksort1.txt");
	qs1_stream << qs.getStream();
	qs1_stream.close();

	output_metrics_file << "QuickSort1" << "," << path.filename().string() << "," << size << "," << qs.getStats() << "\n";

	
	std::memcpy(temp, arr, sizeof(int) * size);
	assert(areEqual(arr, temp, size));

	//
	// Quicksort - First Item as Pivot - Min Partition set to 100
	//
	qs = Quicksort(temp, 0, size - 1, 100, false);

	std::ofstream qs100_stream(output_file_prefix + "_Quicksort100.txt");
	qs100_stream << qs.getStream();
	qs100_stream.close();
	
	output_metrics_file << "QuickSort100" << "," << path.filename().string() << "," << size << "," << qs.getStats() << "\n";

	std::memcpy(temp, arr, sizeof(int) * size);
	assert(areEqual(arr, temp, size));

	//
	// Quicksort - First Item as Pivot - Min Partition set to 50
	//
	qs = Quicksort(temp, 0, size - 1, 50, false);

	std::ofstream qs50_stream(output_file_prefix + "_Quicksort50.txt");
	qs50_stream << qs.getStream();
	qs50_stream.close();
	
	output_metrics_file << "QuickSort50" << "," << path.filename().string() << "," << size << "," << qs.getStats() << "\n";

	std::memcpy(temp, arr, sizeof(int) * size);
	assert(areEqual(arr, temp, size));

	//
	// Quicksort - Median of 3 as Pivot - Min Partition set to 1
	//
	qs = Quicksort(temp, 0, size - 1, 0, true);

	std::ofstream qsmedian3_stream(output_file_prefix + "_QuicksortMedian3.txt");
	qsmedian3_stream << qs.getStream();
	qsmedian3_stream.close();
	
	output_metrics_file << "QuickSortMedian3" << "," << path.filename().string() << "," << size << "," << qs.getStats() << "\n";

	delete[] arr;
	delete[] temp;

}

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

/* Program entry point.
*/
int main(int argc, char* argv[])
{
	argparse::ArgumentParser program("GHaralampopulosLab4");
	program.add_argument("--d", "--directory")
		.required()
		.help("Directory arguement used for parsing input files and generating output files.");

	program.add_argument("--g","--generate-files")
		.default_value<std::vector<int>>({ 50, 1000, 2000, 5000, 10000 })
		.append()// might otherwise be type const char* leading to an error when trying program.get<std::string>
		.help("Using this flag generates a .dat file of random, ordered, and reversed arrays. Defaults to all sizes.");

		
	try {
		program.parse_args(argc, argv);    // Example: ./main --color orange
	}
	catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << program;
		std::exit(1);
	}

	auto dir = program.get<std::string>("--directory");
	auto gen = program.get<std::vector<int>>("--generate-files");
	
	// Check if Directory Exists
	if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir))
	{
		if (program.is_used("--generate-files"))
		{
			generateInputFiles(gen, dir);
			return 0;
		}
		std::string output_dir = dir + "\\output";
		// If ouput directory does exist, create it
		if (!std::filesystem::exists(output_dir))
		{
			std::filesystem::create_directory(output_dir);
		}


		// Create output file
		std::ofstream outfile(output_dir + "\\output_metrics.csv");
		outfile << "Sort,File,Size,Swaps,Comparisons" << "\n";

		try
		{
			for (const auto& entry : std::filesystem::directory_iterator(dir + "\\input"))
			{			
				parseInputFiles(entry.path(), outfile);
			}
		}
		catch (const std::runtime_error& err) {
			std::cerr << err.what() << std::endl;
			std::cerr << program;
			outfile.close();
			std::exit(1);
		}

	}
	
	return 0;
}

