#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
}

MaxHeap::MaxHeap(Vector<HeapNode*>)
{
}

MaxHeap::~MaxHeap()
{
}

long MaxHeap::getSize() const
{
    return heap.getLength();
}

bool MaxHeap::isEmpty() const
{
    return heap.isEmpty();
}

void MaxHeap::insert(HeapNode* hn)
{
    heap.insertEnd(hn);
}


HeapNode* MaxHeap::getMax() const
{
    return heap.getFirst();
}

HeapNode* MaxHeap::extractMax()
{
    return nullptr;
}

long MaxHeap::getParentIndexOfChildAt(long)
{
    return 0;
}

long MaxHeap::getLeftChildIndexOfParentAt(long)
{
    return 0;
}

long MaxHeap::getRightChildIndexOfParentAt(long)
{
    return 0;
}

void MaxHeap::siftUp(long)
{
}

void MaxHeap::siftDown(long)
{
}
