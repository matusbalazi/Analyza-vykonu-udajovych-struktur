#include "BitSetTests.h"
#include "../structures/heap_monitor.h"

BitSetTests::BitSetTests()
{
    srand(time(0));
    aStopwatch = new TimeMeasurement();
}

unsigned int BitSetTests::genNumber(unsigned int pMin, unsigned int pMax)
{
    return (pMax < pMin) ? 0 : (rand() % (pMax - pMin + 1) + pMin);
}

unsigned int BitSetTests::genGroup(unsigned int pScenario)
{
	int group = genNumber(1, 100);
	switch (pScenario) {
	case 1:
		if (group <= BIT_SET_SUM_OP_INSERT_A) {
			return 1;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_A + BIT_SET_SUM_OP_REMOVE_A)) {
			return 2;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_A + BIT_SET_SUM_OP_REMOVE_A + BIT_SET_SUM_OP_CONTAINS_A)) {
			return 3;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_A + BIT_SET_SUM_OP_REMOVE_A + BIT_SET_SUM_OP_CONTAINS_A + BIT_SET_SUM_OP_IS_EQUAL_A)) {
			return 4;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_A + BIT_SET_SUM_OP_REMOVE_A + BIT_SET_SUM_OP_CONTAINS_A + BIT_SET_SUM_OP_IS_EQUAL_A + BIT_SET_SUM_OP_IS_SUBSET_A)) {
			return 5;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_A + BIT_SET_SUM_OP_REMOVE_A + BIT_SET_SUM_OP_CONTAINS_A + BIT_SET_SUM_OP_IS_EQUAL_A + BIT_SET_SUM_OP_IS_SUBSET_A + BIT_SET_SUM_OP_UNION_WITH_A)) {
			return 6;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_A + BIT_SET_SUM_OP_REMOVE_A + BIT_SET_SUM_OP_CONTAINS_A + BIT_SET_SUM_OP_IS_EQUAL_A + BIT_SET_SUM_OP_IS_SUBSET_A + BIT_SET_SUM_OP_UNION_WITH_A + BIT_SET_SUM_OP_INTERSECTION_A)) {
			return 7;
		}
		else
		{
			return 8;
		}
		break;
	case 2:
		if (group <= BIT_SET_SUM_OP_INSERT_B) {
			return 1;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_B + BIT_SET_SUM_OP_REMOVE_B)) {
			return 2;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_B + BIT_SET_SUM_OP_REMOVE_B + BIT_SET_SUM_OP_CONTAINS_B)) {
			return 3;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_B + BIT_SET_SUM_OP_REMOVE_B + BIT_SET_SUM_OP_CONTAINS_B + BIT_SET_SUM_OP_IS_EQUAL_B)) {
			return 4;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_B + BIT_SET_SUM_OP_REMOVE_B + BIT_SET_SUM_OP_CONTAINS_B + BIT_SET_SUM_OP_IS_EQUAL_B + BIT_SET_SUM_OP_IS_SUBSET_B)) {
			return 5;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_B + BIT_SET_SUM_OP_REMOVE_B + BIT_SET_SUM_OP_CONTAINS_B + BIT_SET_SUM_OP_IS_EQUAL_B + BIT_SET_SUM_OP_IS_SUBSET_B + BIT_SET_SUM_OP_UNION_WITH_B)) {
			return 6;
		}
		else if (group <= (BIT_SET_SUM_OP_INSERT_B + BIT_SET_SUM_OP_REMOVE_B + BIT_SET_SUM_OP_CONTAINS_B + BIT_SET_SUM_OP_IS_EQUAL_B + BIT_SET_SUM_OP_IS_SUBSET_B + BIT_SET_SUM_OP_UNION_WITH_B + BIT_SET_SUM_OP_INTERSECTION_B)) {
			return 7;
		}
		else
		{
			return 8;
		}
		break;
	default:
		break;
	}
	return 0;
}

void BitSetTests::test(unsigned int pScenario, std::string pFileName)
{
	Output writer(pFileName);
	int group = 0;
	int element = 0;
	int option = 0;
	bool contains = false;
	writer.writeData("Operacia;Cas;;Velkost bazy\n");
	BaseSet* base = new BaseSet();

	for (int i = 0; i < SUM_OF_REPETITIONS; i++) {
		base->setMinAndMax(10, (10 + 1000 * (i + 1)));
		structures::BitSet* bitSet1 = new structures::BitSet(base);
		structures::BitSet* bitSet2 = new structures::BitSet(base);
		
		for (int j = 0; j < SUM_OP_BIT_SET; j++) {
			group = genGroup(pScenario);
			element = genNumber(1, bitSet1->size());
			structures::BitSet* auxBitset = nullptr;
			switch (group) {
			case 1:
				aStopwatch->start();
				bitSet1->insert(element);
				aStopwatch->stop();
				bitSet2->insert(genNumber(1, bitSet2->size() - 1));
				writer.writeData("Vloz;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			case 2:
				aStopwatch->start();
				bitSet1->remove(element);
				aStopwatch->stop();
				writer.writeData("Odober;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			case 3:
				aStopwatch->start();
				bitSet1->contains(element);
				aStopwatch->stop();
				writer.writeData("Patri;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			case 4:
				aStopwatch->start();
				bitSet1->operator==(*bitSet2);
				aStopwatch->stop();
				writer.writeData("Je rovna;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			case 5:
				aStopwatch->start();
				bitSet1->isSubset(*bitSet2);
				aStopwatch->stop();
				writer.writeData("Je podmnozinou;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				break;
			case 6:
				aStopwatch->start();
				auxBitset = &bitSet1->unionWith(*bitSet2);
				aStopwatch->stop();
				writer.writeData("Zjednotenie;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				delete auxBitset;
				auxBitset = nullptr;
				break;
			case 7:
				aStopwatch->start();
				auxBitset = &bitSet1->intersection(*bitSet2);
				aStopwatch->stop();
				writer.writeData("Prienik;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				delete auxBitset;
				auxBitset = nullptr;
				break;
			case 8:
				aStopwatch->start();
				auxBitset = &bitSet1->substraction(*bitSet2);
				aStopwatch->stop();
				writer.writeData("Rozdiel;");
				writer.writeData(aStopwatch->elapsed().count());
				writer.writeData(";ns;");
				writer.writeData((base->getMax() - base->getMin()));
				writer.writeData("\n");
				aStopwatch->reset();
				delete auxBitset;
				auxBitset = nullptr;
				break;
			default:
				break;
			}	
			delete auxBitset;
			auxBitset = nullptr;
		}	
		delete bitSet1;
		bitSet1 = nullptr;
		delete bitSet2;
		bitSet2 = nullptr;
	}
	delete base;
	base = nullptr;
}

BitSetTests::~BitSetTests()
{
    delete aStopwatch;
    aStopwatch = nullptr;
}
