#ifndef _DOUBLY_LINKEDLIST
#define _DOUBLY_LINKEDLIST

#include "doublyNode.h"
#include <iostream>
using namespace std;

template<typename T>
class doublyLinkedList
{
private:
	doublyNode<T>* Head;
	doublyNode<T>* Tail;
public:
	doublyLinkedList();

	doublyNode<T>* getHead();
	doublyNode<T>* getTail();
	void insertEnd(T item);
	void print();
	void deleteAll();
	~doublyLinkedList();
};

#endif
