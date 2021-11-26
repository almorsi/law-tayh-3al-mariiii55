#include <cassert>
#include "MaxHeapTest.h"

MaxHeapTest::MaxHeapTest()
{
}

MaxHeapTest::~MaxHeapTest()
{
}

void MaxHeapTest::runAllTests()
{
	maxHeapCreation();
	maxHeapInitialyIsEmpty();
	sizeAfterInserting5NullElementsShouldBe0();
	insertMaxElementLastTheRequestTheMax();
	buildAMaxHeapFromAnUnsortedVector();
	testNextMaxAfterExtractOldMax();
	shouldThrowExeceptionWhenExtractingFromEmptyHeap();
	shouldTrhowExeceptionWhenGettingMaxOfAnEmptyHeap();
	shouldBeEmptyAfterBuildingWithEmptyVector();
}

void MaxHeapTest::maxHeapCreation()
{
	MaxHeap mh;
}

void MaxHeapTest::maxHeapInitialyIsEmpty()
{
	MaxHeap mh;
	assert(mh.isEmpty());
}

void MaxHeapTest::sizeAfterInserting5NullElementsShouldBe0()
{
	MaxHeap mh;
	for (int i = 0; i < 5; i++)
		mh.insert(nullptr);
	assert(mh.isEmpty());
	assert(mh.getSize() == 0);
}

void MaxHeapTest::insertMaxElementLastTheRequestTheMax()
{
	MaxHeap mh;

	Keyable* ks = new Keyable[5];
	for (int i = 0; i < 5; i++)
	{
		ks[i].setKey(i);
		mh.insert(&ks[i]);
		assert(mh.getMax()->getKey() == i);
	}
	delete [] ks;
}

void MaxHeapTest::buildAMaxHeapFromAnUnsortedVector()
{
	Vector<Keyable*> vk;
	for (int i = 0; i < 12; i++)
	{
		vk.insertEnd(new Keyable());
		vk.getAt(i)->setKey(i);
	}
	MaxHeap mh(vk);
	assert(mh.getMax()->getKey() == 11);
	for (int i = 0; i < 12; i++)
		delete vk.getAt(i);
}

void MaxHeapTest::testNextMaxAfterExtractOldMax()
{
	Vector<Keyable*> vk;
	for (int i = 0; i < 1000; i++)
	{
		vk.insertEnd(new Keyable());
		vk.getAt(i)->setKey(i);
	}

	MaxHeap mh(vk);
	for (int i = 999; i>=0; i--)
	{
		assert(mh.getSize() == i+1);
		assert(mh.extractMax()->getKey() == i);
	}
	for (int i = 0; i < 1000; i++)
		delete vk.getAt(i);
}

void MaxHeapTest::shouldThrowExeceptionWhenExtractingFromEmptyHeap()
{
	MaxHeap mh;
	try
	{
		mh.extractMax();
	}
	catch (const char*)
	{
		assert(true);
		return;
	}
	assert(false);
}

void MaxHeapTest::shouldTrhowExeceptionWhenGettingMaxOfAnEmptyHeap()
{
	MaxHeap mh;
	try
	{
		mh.getMax();
	}
	catch (const char*)
	{
		assert(true);
		return;
	}
	assert(false);
}

void MaxHeapTest::shouldBeEmptyAfterBuildingWithEmptyVector()
{
	Vector<Keyable*> vk;
	MaxHeap mh(vk);
	assert(mh.isEmpty());
}
