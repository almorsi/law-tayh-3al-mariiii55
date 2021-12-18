#include <algorithm>

#include "MaxHeap.h"

template <typename T>
MaxHeap<T>::MaxHeap()
{
}

template <typename T>
MaxHeap<T>::MaxHeap(const Vector<T>& vk)
{
    for (long i = 0; i < vk.getLength(); i++)
        heap.insertEnd(vk.getAt(i));
    
    for (long i = getParentIndexOfChildAt(heap.getLength() - 1); i >= 0; i--)
        siftDown(i);
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
}

template <typename T>
long MaxHeap<T>::getSize() const
{
    return heap.getLength();
}

template <typename T>
bool MaxHeap<T>::isEmpty() const
{
    return heap.isEmpty();
}

template <typename T>
void MaxHeap<T>::insert(T it)
{
    if (!it) return;

    heap.insertEnd(it);
    siftUp(getSize() - 1);
}

template <typename T>
T MaxHeap<T>::getMax() const
{
    return heap.getFirst();
}

template <typename T>
T MaxHeap<T>::extractMax()
{
    T oldMax;

    oldMax = getMax();
    std::swap(heap.getFirst(), heap.getLast());
    heap.deleteEnd();
    siftDown(0);

    return oldMax;
}

template <typename T>
long MaxHeap<T>::getParentIndexOfChildAt(long i)
{
    if (i == 0) 
        return -1;

    return (i - 1)/2;
}

template <typename T>
long MaxHeap<T>::getLeftChildIndexOfParentAt(long i)
{
    long childIndex;

    childIndex = 2 * i + 1;
    if (childIndex >= getSize())
        return -1;

    return childIndex;
}

template <typename T>
long MaxHeap<T>::getRightChildIndexOfParentAt(long i)
{
    long childIndex;

    childIndex = 2 * i + 2;
    if (childIndex >= getSize())
        return -1;

    return  childIndex;
}

template <typename T>
void MaxHeap<T>::siftUp(long i)
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

template <typename T>
void MaxHeap<T>::siftDown(long i)
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
