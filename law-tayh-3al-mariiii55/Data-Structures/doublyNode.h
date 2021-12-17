#ifndef _DOUBLY_NODE
#define _DOUBLY_NODE

template<typename T>
class doublyNode
{
private:
	T data;
	doublyNode<T>* next;
	doublyNode<T>* prev;
public:
	doublyNode();
	doublyNode(T item);

	T getData();
	doublyNode<T>* getNext();
	doublyNode<T>* getPrev();
	void setData(T item);
	void setNext(doublyNode<T>* nxt);
	void setPrev(doublyNode<T>* prv);

};

#endif