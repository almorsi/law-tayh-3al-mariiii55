#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "vector.h"
#include "HeapNode.h"
#include "Keyable.h"

class MaxHeap
{
public:
	MaxHeap();
	MaxHeap(Vector<HeapNode*>); //O(n)
	~MaxHeap();

	long getSize() const;
	bool isEmpty() const;

	void insert(HeapNode*); //O( lg(n) )
	HeapNode* getMax()const;//O(1)
	HeapNode* extractMax(); //O( lg(n) )
	
private:
	long getParentIndexOfChildAt(long);
	long getLeftChildIndexOfParentAt(long);
	long getRightChildIndexOfParentAt(long);
	void siftUp(long);
	void siftDown(long);

private:
	Vector<HeapNode*> heap;
};
#endif // !MAXHEAP_H
