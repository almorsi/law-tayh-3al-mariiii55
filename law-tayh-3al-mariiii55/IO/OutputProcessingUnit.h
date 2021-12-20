#ifndef OUTPUTPROCESSINGUNIT_H
#define OUTPUTPROCESSINGUNIT_H
#include "Observable.h"
#include "..\Data-Structures\vector.h"
#include "ProcessingBehavior.h"


class OutputProcessingUnit : public Observable
{
public:
	OutputProcessingUnit();
	~OutputProcessingUnit();


	virtual void notify();
	virtual void add(Observer* obs);
	virtual void remove();

	Vector<int>* getProcessedData();
	void setProcessingBehavior(ProcessingBehaviour*);

private:
	ProcessingBehaviour* processingBehavior;
};
#endif // !OUTPUTPROCESSINGUNIT_H

