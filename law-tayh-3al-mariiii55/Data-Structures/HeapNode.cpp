#include <climits>
#include "HeapNode.h"

HeapNode::HeapNode(Keyable* data_v)
	:
	data(data_v)
{
}

HeapNode::~HeapNode()
{
}

void HeapNode::setData(Keyable* d)
{
	data = d;
}

Keyable* HeapNode::getData() const
{
	return data;
}

void HeapNode::setKey(long k)
{
	if (!data)
		throw "setting key for null data";

	data->setKey(k);
}

long HeapNode::getKey() const
{
	if (!data)
		throw "getting key for null data";

	return data->getKey();
}

void HeapNode::increaseKeyBy(long dk)
{
	long k;

	k = data->getKey();
	if ( dk > LONG_MAX - k )
		throw "overflow";

	data->setKey(k + dk);
}
