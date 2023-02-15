#include "PriorityQueueTests.h"
#include "../structures/heap_monitor.h"

PriorityQueueTests::PriorityQueueTests() :
	aOpPush(0), aOpPop(0),
	aOpPeek(0), aSumOfOperations(SUM_OP_ADT_PRIORITY_QUEUE)
{
	srand(time(0));
	aStopwatch = new TimeMeasurement();
}

unsigned int PriorityQueueTests::genNumber(unsigned int pMin, unsigned int pMax)
{
	return (pMax < pMin) ? 0 : (rand() % (pMax - pMin + 1) + pMin);
}

unsigned int PriorityQueueTests::genGroup(unsigned int pScenario)
{
	int group = genNumber(1, 100);
	switch (pScenario) {
	case 1:
		if (group <= PRIORITY_QUEUE_SUM_OP_PUSH_A) {
			return 1;
		}
		else if (group <= (PRIORITY_QUEUE_SUM_OP_PUSH_A + PRIORITY_QUEUE_SUM_OP_POP_A)) {
			return 2;
		}
		else
		{
			return 3;
		}
		break;
	case 2:
		if (group <= PRIORITY_QUEUE_SUM_OP_PUSH_B) {
			return 1;
		}
		else if (group <= (PRIORITY_QUEUE_SUM_OP_PUSH_B + PRIORITY_QUEUE_SUM_OP_POP_B)) {
			return 2;
		}
		else
		{
			return 3;
		}
		break;
	case 3:
		if (group <= PRIORITY_QUEUE_SUM_OP_PUSH_C) {
			return 1;
		}
		else if (group <= (PRIORITY_QUEUE_SUM_OP_PUSH_C + PRIORITY_QUEUE_SUM_OP_POP_C)) {
			return 2;
		}
		else
		{
			return 3;
		}
		break;
	case 4:
		if (group <= aOpPush) {
			return 1;
		}
		else if (group <= (aOpPush + aOpPop)) {
			return 2;
		}
		else
		{
			return 3;
		}
		break;
	default:
		break;
	}
	return 0;
}

void PriorityQueueTests::test(unsigned int pScenario, structures::PriorityQueue<int>* pQueue, std::string pFileName)
{
	Output writer(pFileName);
	int group = 0; 
	int element = 0; 
	int priority = 0;
	writer.writeData("Operacia;Cas;;Pocet prvkov\n");

	for (int i = 0; i < aSumOfOperations; i++) {
		group = genGroup(pScenario);
		if (pQueue->size() == 0) {
			group = 1;
			element = genNumber(1, 10);
		}
		else {
			element = genNumber(1, pQueue->size() - 1);
		}	
		priority = genNumber(1, 10000);
		switch (group) {
		case 1:
			aStopwatch->start();
			pQueue->push(priority, element);
			aStopwatch->stop();
			writer.writeData("Vloz;");
			writer.writeData(aStopwatch->elapsed().count());
			writer.writeData(";ns;");
			writer.writeData(pQueue->size());
			writer.writeData("\n");
			aStopwatch->reset();
		break;
		case 2:
			if (pQueue->size() > 0) {
				aStopwatch->start();
				pQueue->pop();
				aStopwatch->stop();
				writer.writeData("Vyber;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(pQueue->size());
				writer.writeData("\n");
				aStopwatch->reset();
			}
			else {
				writer.writeData("Vyber;");
				writer.writeData(";;;;zamietnute\n");
			}
		break;
		case 3:
			if (pQueue->size() > 0) {
				aStopwatch->start();
				pQueue->peek();
				aStopwatch->stop();
				writer.writeData("Ukaz;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(pQueue->size());
				writer.writeData("\n");
				aStopwatch->reset();
			}
			else {
				writer.writeData("Ukaz;");
				writer.writeData(";;;;zamietnute\n");
			}
		break;
		default:
			break;
		}
	}
}

void PriorityQueueTests::createPriorityQueueScenario(unsigned int pSumOfOperations, 
	unsigned int pPortionPush, unsigned int pPortionPop, unsigned int pPortionPeek, 
	structures::PriorityQueue<int>* pQueue, std::string pFileName)
{
	if ((pSumOfOperations % 100) == 0 &&
		(pPortionPush + pPortionPop + pPortionPeek) == 100) {
		aOpPush = pPortionPush;
		aOpPop = pPortionPop;
		aOpPeek = pPortionPeek;
		aSumOfOperations = pSumOfOperations;
		test(4, pQueue, pFileName);
	}
	else {
		throw Exception();
	}
}

unsigned int PriorityQueueTests::getSumOfPush(unsigned int pOption)
{
	switch (pOption) {
	case 1:
		return PRIORITY_QUEUE_SUM_OP_PUSH_A;
		break;
	case 2:
		return PRIORITY_QUEUE_SUM_OP_PUSH_B;
		break;
	case 3:
		return PRIORITY_QUEUE_SUM_OP_PUSH_C;
		break;
	default:
		break;
	}
}

PriorityQueueTests::~PriorityQueueTests()
{
	delete aStopwatch;
	aStopwatch = nullptr;
}
