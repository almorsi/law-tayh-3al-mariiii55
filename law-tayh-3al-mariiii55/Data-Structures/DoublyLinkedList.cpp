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
		while (h->getNext() != 0)
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
void doublyLinkedList<T>::removeItem(doublyNode<T>* X)
{
	if (X == Head)
	{
		Head = X->getNext();
		X->getNext()->setPrev(nullptr);
		delete X;
	}
	else if (X == Tail)
	{
		Tail = X->getPrev();
		X->getPrev()->setNext(nullptr);
		delete X;
	}
	else
	{
		X->getPrev()->setNext(X->getNext());
		X->getNext()->setPrev(X->getPrev());
		delete X;
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
