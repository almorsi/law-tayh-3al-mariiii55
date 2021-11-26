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
	void sizeAfterInserting5NullElementsShouldBe0();
	void insertMaxElementLastTheRequestTheMax();
	void buildAMaxHeapFromAnUnsortedVector();
	void testNextMaxAfterExtractOldMax();
	void shouldThrowExeceptionWhenExtractingFromEmptyHeap();
	void shouldTrhowExeceptionWhenGettingMaxOfAnEmptyHeap();
	void shouldBeEmptyAfterBuildingWithEmptyVector();
};

#endif // !MAXHEAPTEST_H
