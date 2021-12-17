#ifndef _SORETED_LINKEDLIST
#define _SORETED_LINKEDLIST
#include "Node.h"



class SortedLinkedList
{
private:
	Node* Head;
public:
	SortedLinkedList();
	~SortedLinkedList();
	Node* getHead();
	void setHead(Node* h);
	bool insert(Keyable* item);
	void print();
	void deleteAll();
};

#endif
