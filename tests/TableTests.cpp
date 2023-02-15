#include "TableTests.h"

TableTests::TableTests() :
	aOpInserting(0), aOpAccessing(0), 
	aOpDeleting(0), aSumOfOperations(SUM_OP_ADT_TABLE)
{
	srand(time(0));
	aStopwatch = new TimeMeasurement();
}

unsigned int TableTests::genNumber(unsigned int pMin, unsigned int pMax)
{
	return (pMax < pMin) ? 0 : (rand() % (pMax - pMin + 1) + pMin);
}

unsigned int TableTests::genGroup(unsigned int pScenario)
{
	int group = genNumber(1, 100);
	switch (pScenario) {
	case 1:
		if (group <= TABLE_SUM_OP_INSERT_A) {
			return 1;
		}
		else if (group <= (TABLE_SUM_OP_INSERT_A + TABLE_SUM_OP_ACCESS_A)) {
			return 2;
		}
		else
		{
			return 3;
		}
		break;
	case 2:
		if (group <= TABLE_SUM_OP_INSERT_B) {
			return 1;
		}
		else if (group <= (TABLE_SUM_OP_INSERT_B + TABLE_SUM_OP_ACCESS_B)) {
			return 2;
		}
		else
		{
			return 3;
		}
		break;
	case 3:
		if (group <= aOpInserting) {
			return 1;
		}
		else if (group <= (aOpInserting + aOpAccessing)) {
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

void TableTests::test(unsigned int pScenario, structures::Table<int, int>* pTable, std::string pFileName)
{
	Output writer(pFileName);
	int group = 0;
	int key = 0;
	int data= 0;
	int index = 0;
	int velkost = 0;
	writer.writeData("Operacia;Cas;;Pocet prvkov\n");
	for (int i = 0; i < aSumOfOperations; i++) {
		group = genGroup(pScenario);
		if (pTable->size() == 0) {
			group = 1;
			data = genNumber(1, 10);
		}
		else {
			data = genNumber(1, pTable->size());
		}
		key = index;
		switch (group) {
		case 1:
			velkost = pTable->size();		
			aStopwatch->start();
			pTable->insert(key, data);
			aStopwatch->stop();
			writer.writeData("Vloz na zaklade kluca;");
			writer.writeData(aStopwatch->elapsed().count());
			writer.writeData(";ns;");
			writer.writeData(velkost);
			writer.writeData("\n");
			aStopwatch->reset();
			index++;
			break;
		case 2:
			velkost = pTable->size();
			if (pTable->size() == 0) {
				pTable->insert(key, data);
				aStopwatch->start();
				pTable->operator[](key);
				aStopwatch->stop();
				writer.writeData("Spristupni na zaklade kluca;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(velkost);
				writer.writeData("\n");
				aStopwatch->reset();
				pTable->remove(key);
			}
			else {
				while (!pTable->containsKey(key)) {
					key--;
				}
				aStopwatch->start();
				pTable->operator[](key);
				aStopwatch->stop();
				writer.writeData("Spristupni na zaklade kluca;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(velkost);
				writer.writeData("\n");
				aStopwatch->reset();
			}
			break;
		case 3:
			velkost = pTable->size();
			if (pTable->size() == 0) {
				pTable->insert(key, data);
				aStopwatch->start();
				pTable->remove(key);
				aStopwatch->stop();
				writer.writeData("Odstran na zaklade kluca;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(velkost);
				writer.writeData("\n");
				aStopwatch->reset();
			}
			else {
				while (!pTable->containsKey(key)) {
					key--;
				}
				aStopwatch->start();
				pTable->remove(key);
				aStopwatch->stop();
				writer.writeData("Odstran na zaklade kluca;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData(velkost);
				writer.writeData("\n");
				aStopwatch->reset();
			}
			break;	
		default:
			break;
		}
	}
}

void TableTests::createTableScenario(unsigned int pSumOfOperations, unsigned int pPortionInserting, unsigned int pPortionAccessing, unsigned int pPortionDeleting, structures::Table<int, int>* pTable, std::string pFileName)
{
	if ((pSumOfOperations % 100) == 0 &&
		(pPortionInserting + pPortionAccessing + pPortionDeleting) == 100) {
		aOpInserting = pPortionInserting;
		aOpAccessing = pPortionAccessing;
		aOpDeleting = pPortionDeleting;	
		aSumOfOperations = pSumOfOperations;
		test(3, pTable, pFileName);
	}
	else {
		throw Exception();
	}
}

TableTests::~TableTests()
{
	delete aStopwatch;
	aStopwatch = nullptr;
}
