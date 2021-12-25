#ifndef _DOUBLY_LINKEDLIST
#define _DOUBLY_LINKEDLIST

#include "doublyNode.h"
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
	void removeItem(doublyNode<T>* X);
	void deleteAll();
	~doublyLinkedList();
};

#endif
