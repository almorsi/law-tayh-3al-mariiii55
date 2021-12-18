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
	int size;
public:
	doublyLinkedList();

	doublyNode<T>* getHead();
	doublyNode<T>* getTail();
	int getSize();
	void insertEnd(T item);
	void print();
	void deleteAll();
	~doublyLinkedList();
};

#endif
