#include "LinkedList.h"
#include "Node.h"

#include <iostream>

template <class T>
void LinkedList<T>::push(value_type new_data)
{
	/* allocate node */
	Node<T>* new_node = new Node<T>;

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = head_ref;

	/* move the head to point to the new node */
	head_ref = new_node;
	list_size++;
}


/* Splits the Linkedlist at the position specified
*  
* Index:  0         1        2        3
* Data:  Node1 -> Node2 -> Node3 -> Node4
* Size:   1         2        3        4
* A split at position 2 would modify this to be size 2 (Node1 -> Node2)
* The new LinkedList would be Size 2 (Original List Size(4) - Position(3) + 1)
*/
template <class T>
LinkedList<T> LinkedList<T>::split(int position)
{
	LinkedList<T> splitList;
	Node<T>* temp = head_ref;
	Node<T>* beginning = head_ref;
	// List is empty or just one element
	if (temp == nullptr || position == 0)
	{
		//  return empty list 
		return splitList;
	}
	
	// Find previous node where split will occur
	for(int idx = 0; temp !=nullptr && idx < position; idx++)
	{
		temp = temp->next;
	}

	// Size is two, split in half.
	if (temp->next == nullptr )
	{
		if (position == 1)
		{
			splitList.head_ref = temp;
			splitList.list_size = 1;
			this->head_ref->next = nullptr;
			this->list_size = 1;
			int i = 0;
			return splitList;
		}
		return splitList;
	}
	
	splitList.head_ref = temp->next;
	splitList.list_size = list_size - position-1;
	
	head_ref = temp;
	head_ref->next = nullptr;
	head_ref = beginning;

	this->list_size = position+1;
	
	return splitList;

}

template <class T>
void LinkedList<T>::append(value_type new_data)
{
	// 1. allocate node
	Node<T>* new_node = new Node<T>;

	// Used in step 5
	Node<T>* last = head_ref;

	// 2. Put in the data
	new_node->data = new_data;

	// 3. This new node is going to be
	// the last node, so make next of
	// it as NULL
	new_node->next = nullptr;

	// 4. If the Linked List is empty,
	// then make the new node as head
	if (head_ref == nullptr) {
		head_ref = new_node;
		list_size++;
		return;
	}

	// 5. Else traverse till the last node
	while (last->next != nullptr) {
		last = last->next;
	}

	// 6. Change the next of last node
	last->next = new_node;
	list_size++;
	return;
}


void LinkedList<int>::print()
{
	Node<int>* temp = head_ref;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

void LinkedList<LinkedList<int>>::print()
{
	Node<LinkedList<int>>* temp = head_ref;

	while (temp != nullptr)
	{
		// LinkedList<int>
		auto temp_head = temp->data.head_ref;
		std::cout << "[";
		while (temp_head != nullptr)
		{
			std::cout << temp_head->data << " ";
			temp_head = temp_head->next;
		}
		std::cout << "]";
		temp = temp->next;
	}
}

template class LinkedList<int>;
template class LinkedList<LinkedList<int>>;