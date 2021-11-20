#include "VectorTest.h"

VectorTest::VectorTest()
{
}

VectorTest::~VectorTest()
{
}

void VectorTest::runAllTests()
{
	initializationTest();
	getLengthTestWithoutInsertion();
	getLengthTestAfterInsertingOneItem();
	getLengthTestAfterInsertingTwoItems();
	getCapacityTestWithoutInsertion();
	insertFirstTestAfterInsertingOneLast();
	insertBeginFiveTimesAndinsertEndFiveTimes();
	insert1000ItemsAtTheBegining();
	insertEnd1000Times();
	insertBeginTheninsertEnd100Times();
	setAtShouldThrowExecptionAfterPassingInvalidIndex();
	setAtShouldThrowExecptionAfterPassingValidIndexButInEmptyVector();
	setAtShouldNotThrowExecptionAfterPassingValidIndex();
	getFirstShouldThrowExecptionOnImptyVector();
	getFirstShouldGetTheFirstItemAfterInsertingTowToTheBeggining();
	setFirstShouldThrowExeceptionOnEmptyVector();
	setFirstShouldNotThrowExeceptionOnValidVector();
	InsertBeginThenDeleteBegin();
	insert1000ThenDelete500();
	deleteBeginShouldThrowExecptionIfDeletingMoreThanInserting();
	insertEndThenDeleteEnd();
	deleteEndShouldThrowExecptionOnDeletingFromEmptyVector();
	insertBegin1000ThenDeleteEnd500();
	deleteEndShouldThrowExecptionOnDeletingMoreThanInserting();
	deleteTheSameAmountAsInserting();
}

void VectorTest::initializationTest()
{
	Vector<int> v;
}

void VectorTest::insertFirstTestAfterInsertingOneLast()
{
	Vector<int> v;
	v.insertEnd(1);
	v.insertBegin(2);
	assert(v.getLength() == 2);
}

void VectorTest::getLengthTestWithoutInsertion()
{
	Vector<int> v;
	assert(v.getLength() == 0);
}

void VectorTest::getCapacityTestWithoutInsertion()
{
	Vector<int> v;
	assert(v.getCapacity() == 4);
}

void VectorTest::insertBeginFiveTimesAndinsertEndFiveTimes()
{
	Vector<int> v;
	for (int i = 0; i < 5; i++)
		v.insertBegin(i);
	for (int i = 0; i < 5; i++)
		v.insertEnd(i);
	assert(v.getLength() == 10);
}

void VectorTest::insert1000ItemsAtTheBegining()
{
	Vector<int> v;
	for (int i = 0; i < 1000; i++)
		v.insertBegin(i);
	assert(v.getLength() == 1000);
}

void VectorTest::insertBeginTheninsertEnd100Times()
{
	Vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.insertBegin(i);
		v.insertEnd(i);
	}
	assert(v.getLength() == 200);
}

void VectorTest::insertEnd1000Times()
{
	Vector<int> v;
	for (int i = 0; i < 1000; i++)
		v.insertEnd(i);
	assert(v.getLength() == 1000);
}

void VectorTest::insertOneItemAndTestGetAt0()
{
	Vector<int> v;
	v.insertBegin(10);
	assert(v.getAt(0) == 10);
}

void VectorTest::setAtShouldThrowExecptionAfterPassingInvalidIndex()
{
	Vector<int> v;
	try
	{
		v.setAt(-1, 10);
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void VectorTest::setAtShouldThrowExecptionAfterPassingValidIndexButInEmptyVector()
{
	Vector<int> v;
	try
	{
		v.setAt(0, 10);
	}
	catch(const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void VectorTest::setAtShouldNotThrowExecptionAfterPassingValidIndex()
{
	Vector<int> v;
	v.insertBegin(1);
	try
	{
		v.setAt(0, 2);
	}
	catch (const char* e)
	{
		assert(false);
		return;
	}
	assert(true);
	assert(v.getLength() == 1);
}

void VectorTest::getFirstShouldThrowExecptionOnImptyVector()
{
	Vector<int> v;
	try
	{
		v.getFirst();
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void VectorTest::getFirstShouldGetTheFirstItemAfterInsertingTowToTheBeggining()
{
	Vector<int> v;
	v.insertBegin(1);
	v.insertBegin(2);
	assert(v.getFirst() == 2);
}

void VectorTest::setFirstShouldThrowExeceptionOnEmptyVector()
{
	Vector<int> v;
	try
	{
		v.setFirst(12);
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void VectorTest::setFirstShouldNotThrowExeceptionOnValidVector()
{
	Vector<int> v;
	v.insertBegin(1);
	v.setFirst(2);
	assert(v.getLength() == 1);
}

void VectorTest::InsertBeginThenDeleteBegin()
{
	Vector<int> v;
	v.insertBegin(2);
	v.deleteBegin();
	assert(v.getLength() == 0);
}

void VectorTest::insert1000ThenDelete500()
{
	Vector<int> v;
	for (int i = 0; i < 1000; i++)
		v.insertEnd(i);
	for (int i = 0; i < 500; i++)
		v.deleteBegin();
	assert(v.getLength() == 500);
}

void VectorTest::deleteBeginShouldThrowExecptionIfDeletingMoreThanInserting()
{
	Vector<int> v;
	try
	{
		for (int i = 0; i < 500; i++)
			v.insertBegin(i);
		for (int i = 0; i < 501; i++)
			v.deleteBegin();
		int hold = 2;
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void VectorTest::insertEndThenDeleteEnd()
{
	Vector<int> v;
	v.insertEnd(2);
	v.deleteEnd();
	assert(v.getLength() == 0);
}

void VectorTest::deleteEndShouldThrowExecptionOnDeletingFromEmptyVector()
{
	Vector<int> v;
	try
	{
		v.deleteEnd();
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void VectorTest::insertBegin1000ThenDeleteEnd500()
{
	Vector<int> v;
	for (int i = 0; i < 1000; i++)
		v.insertBegin(i);
	for (int i = 0; i < 500; i++)
		v.deleteEnd();
	assert(v.getLength() == 500);
}

void VectorTest::deleteEndShouldThrowExecptionOnDeletingMoreThanInserting()
{
	Vector<int> v;
	for (int i = 0; i < 250; i++)
		v.insertBegin(i);
	for (int i = 0; i < 250; i++)
		v.insertEnd(i);
	try
	{
		for (int i = 0; i < 501; i++)
			v.deleteEnd();
	}
	catch (const char* e)
	{
		assert(true);
		return;
	}
	assert(false);
}

void VectorTest::deleteTheSameAmountAsInserting()
{
	Vector<int> v;
	for (int i = 0; i < 250; i++)
		v.insertBegin(i);
	for (int i = 0; i < 250; i++)
		v.insertEnd(i);
	for (int i = 0; i < 250; i++)
		v.deleteBegin();
	for (int i = 0; i < 250; i++)
		v.deleteEnd();
	assert(v.getLength() == 0);
}


void VectorTest::getLengthTestAfterInsertingOneItem()
{
	Vector<int> v;
	v.insertEnd(5);
	assert(v.getLength() == 1);
}

void VectorTest::getLengthTestAfterInsertingTwoItems()
{
	Vector<int> v;
	v.insertEnd(2);
	v.insertEnd(1);
	assert(v.getLength() == 2);
}

