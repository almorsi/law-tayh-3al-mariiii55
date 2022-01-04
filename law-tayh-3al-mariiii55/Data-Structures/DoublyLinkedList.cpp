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
		Head = X;
		Tail = X;
	}
	else
	{
		Tail->setNext(X);
		X->setPrev(Tail);
		Tail = X;
	}
	size++;
}

template<typename T>
void doublyLinkedList<T>::removeItem(doublyNode<T>* X)
{
	if (X == Head)
	{
		Head = X->getNext();
		if(Head)
			Head->setPrev(nullptr);
	}
	else if (X == Tail)
	{
		Tail = X->getPrev();
		if(Tail)
			Tail->setNext(nullptr);
	}
	else
	{
		X->getPrev()->setNext(X->getNext());
		X->getNext()->setPrev(X->getPrev());
	}
	delete X;
	size--;
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
