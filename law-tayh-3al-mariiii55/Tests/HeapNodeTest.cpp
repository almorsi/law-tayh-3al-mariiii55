#include <cassert>
#include <climits>

#include "HeapNodeTest.h"

HeapNodeTest::HeapNodeTest()
{
}

HeapNodeTest::~HeapNodeTest()
{
}

void HeapNodeTest::runAllTests()
{
	createHeapNodeTest();
	heapNodeShouldHasKeyGivenWithTheDataPassed();
	heapNodeShouldReturnTheSameDataAsPassed();
	heapNodeShouldChangeTheKeyOfItsDataAfterSettingIt();
	heapNodeShouldThrowExecptionAfterSettingAKeyForANullData();
	heapNodeShouldGetTheKeyAsItsDataItemHas();
	heapNodeShouldThrowExecptionAfterGettingAkeyFromANullData();
	heapNodeShouldIncreaseTheKeyAndSetItInTheData();
	heapNodeShouldThrowExecptionOnIncreasingKeyOverflow();
}

void HeapNodeTest::createHeapNodeTest()
{
	Dummy* d = nullptr;

	HeapNode hn(d);
	assert(hn.getData() == nullptr);
}

void HeapNodeTest::heapNodeShouldHasKeyGivenWithTheDataPassed()
{
	Keyable* d = new Dummy();
	d->setKey(10);

	HeapNode hn(d);
	assert(hn.getKey() == d->getKey());

	delete d;
}

void HeapNodeTest::heapNodeShouldReturnTheSameDataAsPassed()
{
	Keyable* d = new Dummy();

	HeapNode hn(d);
	assert((hn.getData() == d));
	delete d;
}

void HeapNodeTest::heapNodeShouldChangeTheKeyOfItsDataAfterSettingIt()
{
	Keyable* d = new Dummy();

	HeapNode hn(d);
	hn.setKey(12);
	assert(d->getKey() == 12);
	delete d;
}

void HeapNodeTest::heapNodeShouldThrowExecptionAfterSettingAKeyForANullData()
{
	Keyable* d = nullptr;

	HeapNode hn(d);
	try
	{
		hn.setKey(23);
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void HeapNodeTest::heapNodeShouldGetTheKeyAsItsDataItemHas()
{
	Keyable* d = new Dummy();

	d->setKey(223);

	HeapNode hn(d);
	assert(hn.getKey() == 223);
	delete d;
}

void HeapNodeTest::heapNodeShouldThrowExecptionAfterGettingAkeyFromANullData()
{
	Keyable* d = nullptr;
	HeapNode hn(d);
	try
	{
		hn.getKey();
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void HeapNodeTest::heapNodeShouldIncreaseTheKeyAndSetItInTheData()
{
	Keyable* d = new Dummy();
	d->setKey(10);

	HeapNode hn(d);
	hn.increaseKeyBy(15);

	assert(d->getKey() == 10 + 15);

	delete d;
}

void HeapNodeTest::heapNodeShouldThrowExecptionOnIncreasingKeyOverflow()
{
	Keyable* d = new Dummy();
	d->setKey(LONG_MAX - 25);

	HeapNode hn(d);
	try
	{
		hn.increaseKeyBy(26);
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}
