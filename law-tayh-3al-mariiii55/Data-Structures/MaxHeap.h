#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "vector.h"

template <typename T>
class MaxHeap
{
public:
	MaxHeap();
	MaxHeap(const Vector<T>&);
	~MaxHeap();

	long getSize() const;
	bool isEmpty() const;

	void insert(T);
	T getMax()const;
	T extractMax();
	
private:
	long getParentIndexOfChildAt(long);
	long getLeftChildIndexOfParentAt(long);
	long getRightChildIndexOfParentAt(long);
	void siftUp(long);
	void siftDown(long);

private:
	Vector<T> heap;
};
#endif // !MAXHEAP_H
