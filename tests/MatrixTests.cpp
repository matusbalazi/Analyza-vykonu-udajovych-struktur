#include "MatrixTests.h"
#include "../structures/heap_monitor.h"

MatrixTests::MatrixTests()
{
	srand(time(0));
	aStopwatch = new TimeMeasurement();
}

unsigned int MatrixTests::genNumber(unsigned int pMin, unsigned int pMax)
{
	return (pMax < pMin) ? 0 : (rand() % (pMax - pMin + 1) + pMin);
}

unsigned int MatrixTests::testA(structures::Matrix<int>* pMatrix1, structures::Matrix<int>* pMatrix2)
{
	aStopwatch->start();
	structures::Matrix<int>* result = pMatrix1->operator+(*pMatrix2);
	aStopwatch->stop();

	unsigned int duration = aStopwatch->elapsed().count();
	aStopwatch->reset();

	/*pMatrix1->print();
	pMatrix2->print();
	result->print();*/

	delete result;
	result = nullptr;

	return duration;
}

unsigned int MatrixTests::testB(structures::Matrix<int>* pMatrix1, structures::Matrix<int>* pMatrix2)
{
	aStopwatch->start();
	structures::Matrix<int>* result = pMatrix1->operator*(*pMatrix2);
	aStopwatch->stop();

	unsigned int duration = aStopwatch->elapsed().count();
	aStopwatch->reset();

	/*pMatrix1->print();
	pMatrix2->print();
	result->print();*/

	delete result;
	result = nullptr;

	return duration;
}

unsigned int MatrixTests::getSumOp()
{
	return SUM_OP_ADT_MATRIX;
}


MatrixTests::~MatrixTests()
{
	delete aStopwatch;
	aStopwatch = nullptr;
}
