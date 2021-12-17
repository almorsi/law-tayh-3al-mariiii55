#pragma once
#include "Vector.h"

template<typename T>
class Queue
{
public:

	long getCapacity() const;
	long getLength() const;
	bool isEmpty()const;

	void enqueue(const T& x);
	T& dequeue();

	T& getFront() const;
	T& getLast() const;

private:
	Vector <T> vector;
};
