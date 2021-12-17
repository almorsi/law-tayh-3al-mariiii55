#include "DoublyLinkedList.h"


template<typename T>
doublyLinkedList<T>::doublyLinkedList()
{
	Head = nullptr;
	Tail = nullptr;
	size = 0;
}

template<typename T>
doublyNode<T>* doublyLinkedList<T>::getHead()
{
	return Head;
}

template<typename T>
doublyNode<T>* doublyLinkedList<T>::getTail()
{
	return Tail;
}

template<typename T>
int doublyLinkedList<T>::getSize()
{
	return size;
}

template<typename T>
void doublyLinkedList<T>::insertEnd(T item)
{
	doublyNode<T>* X = new doublyNode<T>(item);
	if (Head == nullptr)
	{
		X->setNext(Tail);
		X->setPrev(Head);
		Head = X;
		Tail = X;
		size++;
	}
	else
	{
		doublyNode<T>* h = Head;
		while (h->getNext() != NULL)
		{
			h = h->getNext();
		}
		X->setPrev(h);
		h->setNext(X);
		Tail = X;
		size++;
	}
}


template<typename T>
void doublyLinkedList<T>::print()
{
	doublyNode<T>* h = Head;

	while (h)
	{
		if(h==Head)
			cout << "[" << h->getData() << "]-->";
		else if (h->getNext() != NULL)
			cout << "<--[" << h->getData() << "]-->";
		else
			cout << "<--[" << h->getData() << "]";
		h = h->getNext();
	}
}

template<typename T>
void doublyLinkedList<T>::deleteAll()
{
	doublyNode<T>* P = Head;
	while (Head)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
}

template<typename T>
doublyLinkedList<T>::~doublyLinkedList()
{
	deleteAll();
}
