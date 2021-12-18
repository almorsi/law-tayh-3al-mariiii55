#include "Node.h"
template<typename T>
Node<T>::Node()
{
	next = nullptr;
}

template<typename T>
Node<T>::Node(T item)
{
	data = item;
	next = nullptr;
}

template<typename T>
T Node<T>::getData()
{
	return data;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template<typename T>
void Node<T>::setData(T item)
{
	data = item;
}

template<typename T>
void Node<T>::setNext(Node<T>* nextNode)
{
	next = nextNode;
}