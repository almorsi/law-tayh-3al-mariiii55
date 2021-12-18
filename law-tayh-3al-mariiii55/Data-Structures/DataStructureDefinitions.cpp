#include "SortedLinkedList.h"
#include "HeapNode.h"
#include "MaxHeap.h"
#include "doublyNode.cpp"
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "Vector.h"
#include "Vector.cpp"
#include "Keyable.h"
#include "Mission.h"
#include "Rover.h"
template class Queue<int>;
template class Queue<Mission*>;;

template class Vector<int>;
template class Vector<Keyable*>;

template class doublyNode<Mission*>;

template class doublyLinkedList<int>;
template class doublyLinkedList<Keyable*>;
template class doublyLinkedList<Mission*>;