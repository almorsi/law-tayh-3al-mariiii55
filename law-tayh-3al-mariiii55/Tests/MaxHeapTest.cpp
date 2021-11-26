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
	sizeAfterInserting5ElementsShouldBe5();
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

void MaxHeapTest::sizeAfterInserting5ElementsShouldBe5()
{
	MaxHeap mh;
	for (int i = 0; i < 5; i++)
		mh.insert(nullptr);
	assert(!mh.isEmpty());
	assert(mh.getSize() == 5);
}
