#ifndef _SORETED_LINKEDLIST
#define _SORETED_LINKEDLIST
#include "Node.h"


template<typename T>
class SortedLinkedList
{
private:
	Node<T>* Head;
	int size;
public:
	SortedLinkedList();
	~SortedLinkedList();
	Node<T>* getHead();
	int getSize();
	void setHead(Node<T>* h);
	bool insert(T item);
	void print();
	void deleteAll();
};

#endif
