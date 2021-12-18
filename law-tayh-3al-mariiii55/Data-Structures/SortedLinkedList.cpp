#include "SortedLinkedList.h"
#include <iostream>
using namespace std;
template<typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	Head = nullptr;
}

template<typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	deleteAll();
}

template<typename T>
Node<T>* SortedLinkedList<T>::getHead()
{
	return Head;
}

template<typename T>
int SortedLinkedList<T>::getSize()
{
	return size;
}

template<typename T>
void SortedLinkedList<T>::setHead(Node<T>* h)
{
	Head = h;
}

template<typename T>
bool SortedLinkedList<T>::insert(T item)
{
	size++;
	Node<T>* X = new Node<T>(item);
	if (Head == nullptr)
	{
		X->setNext(Head);
		Head = X;
		return true;
	}
	else
	{
		if (Head->getNext() == NULL)
		{
			if (Head->getData()->getKey() <= item->getKey())
			{
				Head->setNext(X);
				return true;
			}
			else
			{
				X->setNext(Head);
				Head = X;
				return true;
			}
		}
		if (item->getKey() <= Head->getData()->getKey())
		{
			X->setNext(Head);
			Head = X;
			return true;
		}
		Node<T>* current = Head->getNext();
		Node<T>* prev = Head;
		while (current)
		{
			if (item->getKey() <= current->getData()->getKey())
			{
				prev->setNext(X);
				X->setNext(current);
				return true;
			}
			current = current->getNext();
			prev = prev->getNext();
		}
		prev->setNext(X);
		return true;
	}
}

template<typename T>
void SortedLinkedList<T>::print()
{
	Node<T>* h = Head;

	while (h)
	{

		if (h->getNext() != NULL)
			cout << "[" << h->getData()->getKey() << "]-->";
		else
			cout << "[" << h->getData()->getKey() << "]";
		h = h->getNext();
	}
}

template<typename T>
void SortedLinkedList<T>::deleteAll()
{
	Node<T>* P = Head;
	while (Head)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
}