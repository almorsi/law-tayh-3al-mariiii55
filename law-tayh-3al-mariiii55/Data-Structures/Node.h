#ifndef _NODE
#define _NODE

template<typename T>
class Node
{
private:
	T data;
	Node<T>* next;
public:
	Node();
	Node(T item);
	T getData();
	Node<T>* getNext();
	void setData(T item);
	void setNext(Node<T>* nextNode);
};

#endif