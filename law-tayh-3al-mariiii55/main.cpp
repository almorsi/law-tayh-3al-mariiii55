#include "Tests/VectorTest.h"
#include "Tests/HeapNodeTest.h"

int main(void)
{
	VectorTest vt;
	vt.runAllTests();

	HeapNodeTest hnt;
	hnt.runAllTests();

	return 0;
}