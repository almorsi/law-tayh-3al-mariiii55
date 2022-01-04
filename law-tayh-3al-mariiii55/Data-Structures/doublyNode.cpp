#include "doublyNode.h"

template<typename T>
doublyNode<T>::doublyNode()
{
	next = nullptr;
	prev = nullptr;
}

template<typename T>
doublyNode<T>::doublyNode(T item)
{
	data = item;
	next = nullptr;
	prev = nullptr;
}

template<typename T>
T doublyNode<T>::getData()
{
	return data;
}

template<typename T>
doublyNode<T>* doublyNode<T>::getNext()
{

	return next;
}

template<typename T>
doublyNode<T>* doublyNode<T>::getPrev()
{
	return prev;
}

template<typename T>
void doublyNode<T>::setData(T item)
{
	data = item;
}

template<typename T>
void doublyNode<T>::setNext(doublyNode<T>* nxt)
{
	next = nxt;
}

template<typename T>
void doublyNode<T>::setPrev(doublyNode<T>* prv)
{
	prev = prv;
}

template<typename T>
doublyNode<T>::~doublyNode()
{
}
