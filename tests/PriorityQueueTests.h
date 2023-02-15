#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "../structures/heap_monitor.h"
#include "../structures/ds_routines.h"
#include "../structures/priority_queue/priority_queue.h"

#include "../TimeMeasurement.h"
#include "../Output.h"
#include "../Exception.h"

// pocet operacii ADT prioritneho frontu
static const unsigned int SUM_OP_ADT_PRIORITY_QUEUE = 100000;

// pocet scenarov ADT zoznamu
static const unsigned int SUM_SCENARIOS_PRIORITY_QUEUE = 3;

// ADT prioritny front - jednotlive podiely operacii v percentach pre scenare A, B a C
static const unsigned int PRIORITY_QUEUE_SUM_OP_PUSH_A = 35;
static const unsigned int PRIORITY_QUEUE_SUM_OP_POP_A = 35;
static const unsigned int PRIORITY_QUEUE_SUM_OP_PEEK_A = 30;

static const unsigned int PRIORITY_QUEUE_SUM_OP_PUSH_B = 50;
static const unsigned int PRIORITY_QUEUE_SUM_OP_POP_B = 30;
static const unsigned int PRIORITY_QUEUE_SUM_OP_PEEK_B = 20;

static const unsigned int PRIORITY_QUEUE_SUM_OP_PUSH_C = 70;
static const unsigned int PRIORITY_QUEUE_SUM_OP_POP_C = 25;
static const unsigned int PRIORITY_QUEUE_SUM_OP_PEEK_C = 5;

class PriorityQueueTests
{
private:
	unsigned int aOpPush;
	unsigned int aOpPop;
	unsigned int aOpPeek;

	unsigned int aSumOfOperations;
	TimeMeasurement* aStopwatch;
public:
	PriorityQueueTests();
	unsigned int genNumber(unsigned int pMin, unsigned int pMax);
	unsigned int genGroup(unsigned int pScenario);
	void test(unsigned int pScenario, structures::PriorityQueue<int>* pQueue, std::string pFileName);
	void createPriorityQueueScenario(unsigned int pSumOfOperations, unsigned int pPortionPush,
		unsigned int pPortionPop, unsigned int pPortionPeek,
		structures::PriorityQueue<int>* pQueue, std::string pFileName);
	unsigned int getSumOfPush(unsigned int pOption);
	~PriorityQueueTests();
};

