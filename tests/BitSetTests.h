#pragma once

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../structures/heap_monitor.h"
#include "../TimeMeasurement.h"
#include "../structures/set/base_set.h"
#include "../structures/set/bit_set.h"
#include "../Output.h"


static const unsigned int SUM_OF_REPETITIONS = 100;
static const unsigned int SUM_OP_BIT_SET = 1000;

static const unsigned int BIT_SET_SUM_OP_INSERT_A = 15;
static const unsigned int BIT_SET_SUM_OP_REMOVE_A = 10;
static const unsigned int BIT_SET_SUM_OP_CONTAINS_A = 5;
static const unsigned int BIT_SET_SUM_OP_IS_EQUAL_A = 10;
static const unsigned int BIT_SET_SUM_OP_IS_SUBSET_A = 10;
static const unsigned int BIT_SET_SUM_OP_UNION_WITH_A = 15;
static const unsigned int BIT_SET_SUM_OP_INTERSECTION_A = 20;
static const unsigned int BIT_SET_SUM_OP_SUBSTRACTION_A = 15;

static const unsigned int BIT_SET_SUM_OP_INSERT_B = 20;
static const unsigned int BIT_SET_SUM_OP_REMOVE_B = 20;
static const unsigned int BIT_SET_SUM_OP_CONTAINS_B = 5;
static const unsigned int BIT_SET_SUM_OP_IS_EQUAL_B = 10;
static const unsigned int BIT_SET_SUM_OP_IS_SUBSET_B = 10;
static const unsigned int BIT_SET_SUM_OP_UNION_WITH_B = 20;
static const unsigned int BIT_SET_SUM_OP_INTERSECTION_B = 5;
static const unsigned int BIT_SET_SUM_OP_SUBSTRACTION_B = 10;


class BitSetTests
{
private:
	TimeMeasurement* aStopwatch;

public:
	BitSetTests();
	unsigned int genNumber(unsigned int pMin, unsigned int pMax);
	unsigned int genGroup(unsigned int pScenario);
	void test(unsigned int pScenario, std::string pFileName);
	~BitSetTests();
};

