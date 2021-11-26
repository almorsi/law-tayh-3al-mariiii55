#ifndef MAXHEAPTEST_H
#define MAXhEAPTEST_H

#include "../Data-Structures/MaxHeap.h"

class MaxHeapTest
{
public:
	MaxHeapTest();
	~MaxHeapTest();
	void runAllTests();
private:
	void maxHeapCreation();
	void maxHeapInitialyIsEmpty();
	void sizeAfterInserting5ElementsShouldBe5();
};

#endif // !MAXHEAPTEST_H
