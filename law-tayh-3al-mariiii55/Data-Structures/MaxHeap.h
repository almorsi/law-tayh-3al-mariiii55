#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "vector.h"
#include "Keyable.h"

class MaxHeap
{
public:
	MaxHeap();
	MaxHeap(const Vector<Keyable*>&); //O(n)
	~MaxHeap();

	long getSize() const;
	bool isEmpty() const;

	void insert(Keyable*); //O( lg(n) )
	Keyable* getMax()const; //O(1)
	Keyable* extractMax();  //O( lg(n) )
	
private:
	long getParentIndexOfChildAt(long);
	long getLeftChildIndexOfParentAt(long);
	long getRightChildIndexOfParentAt(long);
	void siftUp(long);
	void siftDown(long);

private:
	Vector<Keyable*> heap;
};
#endif // !MAXHEAP_H
