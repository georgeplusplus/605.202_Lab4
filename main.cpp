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

/* Program entry point.
*/
int main(int argc, char* argv[])
{
	Mergesort ms = Mergesort();
	return 0;
}

