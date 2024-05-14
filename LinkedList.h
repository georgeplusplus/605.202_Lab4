#pragma once

#include "Node.h"

template <class T>
class LinkedList
{
public:

	// private, no need to expose implementation
	typedef Node<T> node_type;

	// From now on, T should never appear
	typedef node_type* node_pointer;

	typedef typename node_type::value_type value_type;
	typedef typename node_type::reference_type reference_type;
	typedef typename node_type::const_reference_type const_reference_type;
	typedef typename node_type::pointer_type pointer_type;
	typedef typename node_type::const_pointer_type const_pointer_type;

	void append(value_type info);
	void push(value_type new_data);
	void print();
	LinkedList<T> split(int position);

	node_pointer head() { return head_ref; };
	//value_type getData() { return head_ref->data; };
	node_pointer head_ref = nullptr;
	int list_size = 0;

	
};