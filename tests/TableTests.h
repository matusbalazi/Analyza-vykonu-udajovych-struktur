#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

#include "../structures/ds_routines.h"
#include "../structures/table/table.h"
#include "../structures/heap_monitor.h"

#include "../TimeMeasurement.h"
#include "../Output.h"
#include "../Exception.h"

// pocet operacii ADT tabulka
static const unsigned int SUM_OP_ADT_TABLE = 100000;

// ADT tabulka - jednotlive podiely operacii v percentach pre scenare A a B
static const unsigned int TABLE_SUM_OP_INSERT_A = 30;
static const unsigned int TABLE_SUM_OP_ACCESS_A = 60;
static const unsigned int TABLE_SUM_OP_DELETE_A = 10;

static const unsigned int TABLE_SUM_OP_INSERT_B = 45;
static const unsigned int TABLE_SUM_OP_ACCESS_B = 10;
static const unsigned int TABLE_SUM_OP_DELETE_B = 45;

class TableTests
{
private:
	unsigned int aOpInserting;
	unsigned int aOpAccessing;
	unsigned int aOpDeleting;
	unsigned int aSumOfOperations;
	TimeMeasurement* aStopwatch;

public:
	TableTests();
	unsigned int genNumber(unsigned int pMin, unsigned int pMax);
	unsigned int genGroup(unsigned int pScenario);
	void test(unsigned int pScenario, structures::Table<int, int>* pTable,
		std::string pFileName);
	void createTableScenario(unsigned int pSumOfOperations, unsigned int pPortionInserting,
		unsigned int pPortionAccessing, unsigned int pPortionDeleting,
		structures::Table<int, int>* pTable, std::string pFileName);
	~TableTests();
};

