#include "ListTests.h"
#include "../structures/heap_monitor.h"

ListTests::ListTests() :
	aOpInserting(0), aOpDeleting(0),
	aOpAccessing(0), aOpSearching(0), aSumOfOperations(SUM_OP_ADT_LIST)
{
	srand(time(0));
	aStopwatch = new TimeMeasurement();
}

unsigned int ListTests::genNumber(unsigned int pMin, unsigned int pMax)
{
	return (pMax < pMin) ? 0 : (rand() % (pMax - pMin + 1) + pMin);
}

unsigned int ListTests::genGroup(unsigned int pScenario)
{
	int group = genNumber(1, 100);
	switch (pScenario) {
	case 1:
		if (group <= LIST_SUM_OP_INSERT_A) {
			return 1;
		}
		else if (group <= (LIST_SUM_OP_INSERT_A + LIST_SUM_OP_DELETE_A)) {
			return 2;
		}
		else if (group <= (LIST_SUM_OP_INSERT_A + LIST_SUM_OP_DELETE_A + LIST_SUM_OP_ACCESS_A)) {
			return 3;
		}
		else
		{
			return 4;
		}
		break;
	case 2:
		if (group <= LIST_SUM_OP_INSERT_B) {
			return 1;
		}
		else if (group <= (LIST_SUM_OP_INSERT_B + LIST_SUM_OP_DELETE_B)) {
			return 2;
		}
		else if (group <= (LIST_SUM_OP_INSERT_B + LIST_SUM_OP_DELETE_B + LIST_SUM_OP_ACCESS_B)) {
			return 3;
		}
		else
		{
			return 4;
		}
		break;
	case 3:
		if (group <= LIST_SUM_OP_INSERT_C) {
			return 1;
		}
		else if (group <= (LIST_SUM_OP_INSERT_C + LIST_SUM_OP_DELETE_C)) {
			return 2;
		}
		else if (group <= (LIST_SUM_OP_INSERT_C + LIST_SUM_OP_DELETE_C + LIST_SUM_OP_ACCESS_C)) {
			return 3;
		}
		else
		{
			return 4;
		}
		break;
	case 4:
		if (group <= aOpInserting) {
			return 1;
		}
		else if (group <= (aOpInserting + aOpDeleting)) {
			return 2;
		}
		else if (group <= (aOpInserting + aOpDeleting + aOpAccessing)) {
			return 3;
		}
		else
		{
			return 4;
		}
		break;
	default:
		break;
	}
	return 0;
}

void ListTests::test(unsigned int pScenario, structures::List<int>* pList, std::string pFileName)
{
	Output writer(pFileName);
	int group = 0; 
	int element = 0;
	int operation = 0;
	int index = 0;
	writer.writeData("Operacia;Cas;;Pocet prvkov\n");
	for (int i = 0; i < aSumOfOperations; i++) {
		group = genGroup(pScenario);
		if (pList->size() == 0) {
			group = 1;
			element = genNumber(1, 10);
		}
		else {
			element = genNumber(1, pList->size() - 1);
		}
		switch (group) {
		case 1:
			operation = genNumber(1, 3);
			switch (operation) {
			case 1:
				aStopwatch->start();
				pList->insert(element, 0);
				aStopwatch->stop();
				writer.writeData("Vloz prvy;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(pList->size());
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			case 2:
				aStopwatch->start();
				pList->add(element);
				aStopwatch->stop();
				writer.writeData("Vloz posledny;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(pList->size());
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			case 3:
				index = genNumber(0, pList->size());
				aStopwatch->start();
				pList->insert(element, index);
				aStopwatch->stop();
				writer.writeData("Vloz na index;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(pList->size());
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			default:
				break;
			}
		break;
		case 2:
			operation = genNumber(1, 3);
			switch (operation) {
			case 1:
				if (pList->size() > 0) {
					aStopwatch->start();
					pList->removeAt(0);
					aStopwatch->stop();
					writer.writeData("Zrus prvy;");
					writer.writeData(aStopwatch->elapsed().count());
					writer.writeData(";ns;");
					writer.writeData(pList->size());
					writer.writeData("\n");
					aStopwatch->reset();
				}
				else {
					writer.writeData("Zrus prvy;");
					writer.writeData(";;;;zamietnute\n");
				}
				break;
			case 2:
				if (pList->size() > 0) {
					aStopwatch->start();
					pList->removeAt(pList->size() - 1);
					aStopwatch->stop();
					writer.writeData("Zrus posledny;");
					writer.writeData(aStopwatch->elapsed().count());
					writer.writeData(";ns;");
					writer.writeData(pList->size());
					writer.writeData("\n");
					aStopwatch->reset();
				}
				else {
					writer.writeData("Zrus posledny;");
					writer.writeData(";;;;zamietnute\n");
				}
				break;
			case 3:
				if (pList->size() > 0) {
					index = genNumber(0, pList->size() - 1);
					aStopwatch->start();
					pList->removeAt(index);
					aStopwatch->stop();
					writer.writeData("Zrus na indexe;");
					writer.writeData(aStopwatch->elapsed().count());
					writer.writeData(";ns;");
					writer.writeData(pList->size());
					writer.writeData("\n");
					aStopwatch->reset();
				}
				else {
					writer.writeData("Zrus na indexe;");
					writer.writeData(";;;;zamietnute\n");
				}
				break;
			default:
				break;
			}
		break;
		case 3:
			operation = genNumber(1, 2);
			switch (operation) {
			case 1:
				if (pList->size() > 0) {
					index = genNumber(0, pList->size() - 1);
					aStopwatch->start();
					pList->operator[](index);
					aStopwatch->stop();
					writer.writeData("Spristupni;");
					writer.writeData(aStopwatch->elapsed().count());
					writer.writeData(";ns;");
					writer.writeData(pList->size());
					writer.writeData("\n");
					aStopwatch->reset();
				}
				else {
					writer.writeData("Spristupni;");
					writer.writeData(";;;;zamietnute\n");
				}
				break;
			case 2:
				if (pList->size() > 0) {
					index = genNumber(0, pList->size() - 1);
					aStopwatch->start();
					pList->operator[](index) = element;
					aStopwatch->stop();
					writer.writeData("Nastav;");
					writer.writeData(aStopwatch->elapsed().count());
					writer.writeData(";ns;");
					writer.writeData(pList->size());
					writer.writeData("\n");
					aStopwatch->reset();
				}
				else {
					writer.writeData("Nastav;");
					writer.writeData(";;;;zamietnute\n");
				}
				break;
			default:
				break;
			}
		break;
		case 4:
			if (pList->size() > 0) {
				aStopwatch->start();
				pList->getIndexOf(element);
				aStopwatch->stop();
				writer.writeData("Index prvku;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(pList->size());
				writer.writeData("\n");
				aStopwatch->reset();
			}
			else {
				writer.writeData("Index prvku;");
				writer.writeData(";;;;zamietnute\n");
			}
		break;
		default:
			break;
		}
	}
}

void ListTests::createListScenario(unsigned int pSumOfOperations, unsigned int pPortionInserting,
	unsigned int pPortionDeleting, unsigned int pPortionAccessing, unsigned int pPortionSearching,
	structures::List<int>* pList, std::string pFileName)
{
	if ((pSumOfOperations % 100) == 0 &&
		(pPortionInserting + pPortionDeleting + pPortionAccessing + pPortionSearching) == 100) {
		aOpInserting = pPortionInserting;
		aOpDeleting = pPortionDeleting;
		aOpAccessing = pPortionAccessing;
		aOpSearching = pPortionSearching;
		aSumOfOperations = pSumOfOperations;
		test(4, pList, pFileName);
	}
	else {
		throw Exception();
	}
}

ListTests::~ListTests()
{
	delete aStopwatch;
	aStopwatch = nullptr;
}
