#ifndef _NODE
#define _NODE
#include "Keyable.h"


class Node
{
private:
	Keyable* data;
	Node* next;
public:
	Node();
	Node(Keyable* item);
	Keyable* getData();
	Node* getNext();
	void setData(Keyable* item);
	void setNext(Node* nextNode);
};

#endif