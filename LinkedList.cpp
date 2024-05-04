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
		while (temp_head != nullptr)
		{
			std::cout << temp_head->data << " ";
			temp_head = temp_head->next;
		}
		
		temp = temp->next;
	}
}

template class LinkedList<int>;
template class LinkedList<LinkedList<int>>;