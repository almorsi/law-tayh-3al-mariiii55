#include "Queue.h"

template<class T>
long Queue<T>::getCapacity() const
{
	return vector.getCapacity();
}

template< class T>
long Queue<T>::getLength() const
{
	return vector.getLength();
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return vector.isEmpty();
}

template< class T>
void  Queue<T>::enqueue(const T& x)
{
	vector.insertEnd(x);
}

template< class T>
T& Queue<T>::dequeue()
{
		T& data;

		data = vector.getFirst();
		vector.deleteBegin();
		return data;
}

template< class T>
T& Queue<T>::getFront() const
{
	return vector.getFirst();
}

template< class T>
T& Queue<T>::getLast() const
{
	return vector.getLast();
}
