#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

#include "../structures/ds_routines.h"
#include "../structures/list/list.h"
#include "../structures/heap_monitor.h"

#include "../TimeMeasurement.h"
#include "../Output.h"
#include "../Exception.h"

// pocet operacii ADT zoznamu
static const unsigned int SUM_OP_ADT_LIST = 100000;

// pocet scenarov ADT zoznamu
static const unsigned int SUM_SCENARIOS = 3;

// ADT zoznam - jednotlive podiely operacii v percentach pre scenare A, B a C
static const unsigned int LIST_SUM_OP_INSERT_A = 20;
static const unsigned int LIST_SUM_OP_DELETE_A = 20;
static const unsigned int LIST_SUM_OP_ACCESS_A = 50;
static const unsigned int LIST_SUM_OP_SEARCH_A = 10;

static const unsigned int LIST_SUM_OP_INSERT_B = 35;
static const unsigned int LIST_SUM_OP_DELETE_B = 35;
static const unsigned int LIST_SUM_OP_ACCESS_B = 20;
static const unsigned int LIST_SUM_OP_SEARCH_B = 10;

static const unsigned int LIST_SUM_OP_INSERT_C = 45;
static const unsigned int LIST_SUM_OP_DELETE_C = 45;
static const unsigned int LIST_SUM_OP_ACCESS_C = 5;
static const unsigned int LIST_SUM_OP_SEARCH_C = 5;

class ListTests
{
private:
	unsigned int aOpInserting;
	unsigned int aOpDeleting;
	unsigned int aOpAccessing;
	unsigned int aOpSearching;
	unsigned int aSumOfOperations;
	TimeMeasurement* aStopwatch;

public:
	ListTests();
	unsigned int genNumber(unsigned int pMin, unsigned int pMax);
	unsigned int genGroup(unsigned int pScenario);
	void test(unsigned int pScenario, structures::List<int>* pList, 
		std::string pFileName);
	void createListScenario(unsigned int pSumOfOperations, unsigned int pPortionInserting,
		unsigned int pPortionDeleting, unsigned int pPortionAccessing, unsigned int pPortionSearching,
		structures::List<int>* pList, std::string pFileName);
	~ListTests();
};

