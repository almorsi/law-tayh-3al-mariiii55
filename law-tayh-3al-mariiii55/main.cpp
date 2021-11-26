#include "Tests/VectorTest.h"
#include "Tests/HeapNodeTest.h"
#include "Tests/MaxHeapTest.h"

int main(void)
{
	VectorTest vt;
	vt.runAllTests();

	HeapNodeTest hnt;
	hnt.runAllTests();

	MaxHeapTest mh;
	mh.runAllTests();
	return 0;
}