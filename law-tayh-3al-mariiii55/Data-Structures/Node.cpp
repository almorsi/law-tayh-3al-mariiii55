#include "Node.h"
Node::Node()
{
	next = nullptr;
}

Node::Node(Keyable* item)
{
	data = item;
	next = nullptr;
}

Keyable* Node::getData()
{
	return data;
}

Node* Node::getNext()
{
	return next;
}

void Node::setData(Keyable* item)
{
	data = item;
}

void Node::setNext(Node* nextNode)
{
	next = nextNode;
}