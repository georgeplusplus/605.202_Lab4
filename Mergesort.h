#pragma once

#include "Mergesort.h"
#include "LinkedList.h"
#include "Node.h"

#include <string>


class Mergesort
{
public:
	Mergesort();
	std::string getStats();
	void merge(LinkedList<LinkedList<int>>& list_of_list, Node<int>** merged_list);

private:
	void moveNode(Node<int>** destRef, Node<int>** sourceRef);
	Node<int>* sortedMerge(Node<int>* a, Node<int>* b);

	int swapCount = 0;
	int compCount = 0;
};
