#pragma once
#include <iostream>

#include "../structures/heap_monitor.h"
#include "../structures/matrix/matrix.h"
#include "../TimeMeasurement.h"

static const unsigned int SUM_OP_ADT_MATRIX = 300;

class MatrixTests
{
private:
	TimeMeasurement* aStopwatch;
public:
	MatrixTests();
	unsigned int genNumber(unsigned int pMin, unsigned int pMax);
	unsigned int testA(structures::Matrix<int>* pMatrix1, structures::Matrix<int>* pMatrix2);
	unsigned int testB(structures::Matrix<int>* pMatrix1, structures::Matrix<int>* pMatrix2);
	unsigned int getSumOp();
	~MatrixTests();
};

