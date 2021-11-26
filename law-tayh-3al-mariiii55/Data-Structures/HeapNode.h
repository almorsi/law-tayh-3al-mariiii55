#ifndef HEAPNODE_H
#define HEAPNODE_H

#include "Keyable.h"

class HeapNode
{
public:
	HeapNode(Keyable*);
	~HeapNode();

	void setData(Keyable*);
	Keyable* getData() const;

	void setKey(long);
	long getKey() const;
	void increaseKeyBy(long);

private:
	Keyable* data;
};

#endif // !HEAPNODE_H
