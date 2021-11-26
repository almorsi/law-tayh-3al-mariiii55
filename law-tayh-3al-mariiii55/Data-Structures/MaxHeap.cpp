#include <algorithm>

#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
}

MaxHeap::MaxHeap(const Vector<Keyable*>& vk)
{
    for (long i = 0; i < vk.getLength(); i++)
        heap.insertEnd(vk.getAt(i));
    
    for (long i = getParentIndexOfChildAt(heap.getLength() - 1); i >= 0; i--)
        siftDown(i);
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

void MaxHeap::insert(Keyable* it)
{
    if (!it) return;

    heap.insertEnd(it);
    siftUp(getSize() - 1);
}


Keyable* MaxHeap::getMax() const
{
    return heap.getFirst();
}

Keyable* MaxHeap::extractMax()
{
    Keyable* oldMax;

    oldMax = getMax();
    std::swap(heap.getFirst(), heap.getLast());
    heap.deleteEnd();
    siftDown(0);

    return oldMax;
}

long MaxHeap::getParentIndexOfChildAt(long i)
{
    if (i == 0) 
        return -1;

    return (i - 1)/2;
}

long MaxHeap::getLeftChildIndexOfParentAt(long i)
{
    long childIndex;

    childIndex = 2 * i + 1;
    if (childIndex >= getSize())
        return -1;

    return childIndex;
}

long MaxHeap::getRightChildIndexOfParentAt(long i)
{
    long childIndex;

    childIndex = 2 * i + 2;
    if (childIndex >= getSize())
        return -1;

    return  childIndex;
}

void MaxHeap::siftUp(long i)
{
    long childIndex, parentIndex;

    childIndex = i; parentIndex = getParentIndexOfChildAt(childIndex);
    
    if (parentIndex == -1) //ith node is the root node
        return;
    
    if (heap.getAt(childIndex)->getKey() > heap.getAt(parentIndex)->getKey())
    {
        std::swap(heap.getAt(childIndex), heap.getAt(parentIndex));
        siftUp(parentIndex);
    }

    return;
}

void MaxHeap::siftDown(long i)
{
    long leftChildIndex, rightChildIndex, maxOfChildsIndex, parentIndex;
    
    parentIndex = i;
    leftChildIndex = getLeftChildIndexOfParentAt(parentIndex);
    rightChildIndex = getRightChildIndexOfParentAt(parentIndex);

    if (leftChildIndex == -1 && rightChildIndex == -1)
        return;
    else if (leftChildIndex == -1)
        maxOfChildsIndex = rightChildIndex;
    else if (rightChildIndex == -1)
        maxOfChildsIndex = leftChildIndex;
    else if (heap.getAt(leftChildIndex)->getKey() >= heap.getAt(rightChildIndex)->getKey())
        maxOfChildsIndex = leftChildIndex;
    else
        maxOfChildsIndex = rightChildIndex;

    if (heap.getAt(parentIndex)->getKey() < heap.getAt(maxOfChildsIndex)->getKey())
    {
        std::swap(heap.getAt(parentIndex), heap.getAt(maxOfChildsIndex));
        siftDown(maxOfChildsIndex);
    }

    return;
}
