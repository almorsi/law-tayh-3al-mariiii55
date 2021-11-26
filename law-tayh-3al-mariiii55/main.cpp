#include "Tests/VectorTest.h"
#include "Tests/HeapNodeTest.h"
#include "Tests/MaxHeapTest.h"
#include "IO/TestGenerator.h"

int main(void)
{
	VectorTest vt;
	vt.runAllTests();

	HeapNodeTest hnt;
	hnt.runAllTests();

	MaxHeapTest mht;
	mht.runAllTests();


	/******************************************************************
	 * will generate an input file in the format reqiured, 
	 * we can use this generated file to be the input of our simulation
	 */
	TestGenerator tg("test.txt");
	if (tg.canGenerateTestCase())
		tg.generateTestCase();
	/*****************************************************************/

	return 0;
}