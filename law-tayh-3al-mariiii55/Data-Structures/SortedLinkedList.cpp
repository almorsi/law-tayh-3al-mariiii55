#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

SortedLinkedList::SortedLinkedList()
{
	Head = nullptr;
}

SortedLinkedList::~SortedLinkedList()
{
	deleteAll();
}

Node* SortedLinkedList::getHead()
{
	return Head;
}

void SortedLinkedList::setHead(Node* h)
{
	Head = h;
}

bool SortedLinkedList::insert(Keyable* item)
{
	Node* X = new Node(item);
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
		Node* current = Head->getNext();
		Node* prev = Head;
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

void SortedLinkedList::print()
{
	Node* h = Head;

	while (h)
	{

		if (h->getNext() != NULL)
			cout << "[" << h->getData()->getKey() << "]-->";
		else
			cout << "[" << h->getData()->getKey() << "]";
		h = h->getNext();
	}
}

void SortedLinkedList::deleteAll()
{
	Node* P = Head;
	while (Head)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
}