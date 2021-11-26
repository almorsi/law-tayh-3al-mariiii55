#ifndef HEAPNODETEST_H
#define HEAPNODETEST_H

#include "../Data-Structures/HeapNode.h"

class Dummy : public Keyable
{
};

class HeapNodeTest
{
public:
	HeapNodeTest();
	~HeapNodeTest();
	void runAllTests();
private:
	void createHeapNodeTest();
	void heapNodeShouldHasKeyGivenWithTheDataPassed();
	void heapNodeShouldReturnTheSameDataAsPassed();
	void heapNodeShouldChangeTheKeyOfItsDataAfterSettingIt();
	void heapNodeShouldThrowExecptionAfterSettingAKeyForANullData();
	void heapNodeShouldGetTheKeyAsItsDataItemHas();
	void heapNodeShouldThrowExecptionAfterGettingAkeyFromANullData();
	void heapNodeShouldIncreaseTheKeyAndSetItInTheData();
	void heapNodeShouldThrowExecptionOnIncreasingKeyOverflow();
};

#endif // !HEAPNODETEST_H

