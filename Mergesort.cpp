#include "Mergesort.h"
#include "LinkedList.h"
#include "Node.h"

#include <iostream>
#include <string>

Mergesort::Mergesort()
{
    
    LinkedList<int> lista =  LinkedList<int>();
    LinkedList<int> listb = LinkedList<int>();
    LinkedList<int> listc = LinkedList<int>();
    LinkedList<int> listd = LinkedList<int>();

    lista.append(5); //
    lista.append(10); //
    lista.append(15); //
    lista.append(16); //
    
    listb.push(20); //
    listb.push(3); //
    listb.push(2); //

    
    listc.push(12); //
    listc.push(7); //
    listc.push(1); //

    listd.push(22); //
    listd.push(16); //
    listd.push(11); //
    

    LinkedList<LinkedList<int>> list_of_list = LinkedList<LinkedList<int>>();
    list_of_list.push(listd);
    list_of_list.push(listc);
    list_of_list.push(listb);
    list_of_list.push(lista);
    
    list_of_list.print();
    std::cout << "\n";
    
    //auto output = sortedMerge(lista.head(), listb.head());

    Node<int>* merged_list = new Node<int>();

    merge(list_of_list, &merged_list);
    LinkedList<int> output = LinkedList<int>();
    output.head_ref = merged_list; 
    output.print();

    return;
    
}

void Mergesort::merge(LinkedList<LinkedList<int>>& list_of_list, Node<int>** merged_list)
{
    
    if (list_of_list.head() == nullptr || list_of_list.head()->next == nullptr)
    {
        return;
    }
    auto split_list = list_of_list.split(list_of_list.list_size / 2);

    merge(list_of_list, merged_list);
    merge(split_list, merged_list);

    *merged_list = sortedMerge(list_of_list.head()->data.head(), split_list.head()->data.head());
    list_of_list.head_ref->data.head_ref = *merged_list;

}

void Mergesort::moveNode(Node<int>** destRef, Node<int>** sourceRef)
{
    /* the front source node */
    Node<int>* newNode = *sourceRef;

    /* Advance the source pointer */
    *sourceRef = newNode->next;

    /* Link the old dest of the new node */
    newNode->next = *destRef;

    /* Move dest to point to the new node */
    *destRef = newNode;
}

Node<int>* Mergesort::sortedMerge(Node<int>* a, Node<int>* b)
{
    /* a dummy first node to hang the result on */
    Node<int> dummy;

    /* tail points to the last result node */
    Node<int>* tail = &dummy;

    /* so tail->next is the place to
    add new nodes to the result. */
    dummy.next = NULL;
    while (1) {
        if (a == NULL) {
            /* if either list runs out, use the
            other list */
            tail->next = b;
            break;
        }
        else if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            moveNode(&(tail->next), &a);
        else
            moveNode(&(tail->next), &b);

        tail = tail->next;
    }
    return dummy.next;
    
}


std::string Mergesort::getStats()
{
	return std::string(std::to_string(swapCount) + "," + std::to_string(compCount));
}