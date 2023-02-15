#pragma once

#include "Output.h"
#include "Input.h"
#include "tests/ListTests.h"
#include "tests/PriorityQueueTests.h"
#include "tests/MatrixTests.h"
#include "tests/BitSetTests.h"
#include "tests/TableTests.h"
#include "structures/list/array_list.h"
#include "structures/list/linked_list.h"
#include "structures/list/doubly_circular_linked_list.h"
#include "structures/priority_queue/priority_queue_sorted_array_list.h"
#include "structures/priority_queue/heap.h"
#include "structures/matrix/matrix_continuous.h"
#include "structures/matrix/matrix_discontinuous.h"
#include "structures/priority_queue/priority_queue_two_lists.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/table/treap.h"
#include "structures/table/hash_table.h"
#include "structures/table/binary_search_tree.h"
#include "structures/heap_monitor.h"

class Tests
{
private:
	ListTests* aList;
	PriorityQueueTests* aQueue;
	MatrixTests* aMatrix;
	BitSetTests* aBitSet;
	TableTests* aTable;
public:
	Tests();
	void callListTest(unsigned int pScenario, structures::List<int>* pList, std::string pFileName);
	void callPriorityQueueTest(unsigned int pScenario, structures::PriorityQueue<int>* pQueue, std::string pFileName);
	void callMatrixTest(unsigned int pScenario, std::string pFileName);
	void callBitSetTest(unsigned int pScenario, std::string pFileName);
	void callTableTest(unsigned int pScenario, structures::Table<int, int>* pTable, std::string pFileName);
	void run();
	~Tests();
};

