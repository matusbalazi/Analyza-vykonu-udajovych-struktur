#include "Tests.h"
#include "structures/heap_monitor.h"

Tests::Tests()
{
	aList = new ListTests();
	aQueue = new PriorityQueueTests();
	aMatrix = new MatrixTests();
	aBitSet = new BitSetTests();
	aTable = new TableTests();
}

void Tests::callListTest(unsigned int pScenario, structures::List<int>* pList, std::string pFileName)
{
	unsigned int sumOfOperations, porInsert, porDelete, porAccess, porSearch;

	if (pScenario == 4) {
		Output writer("VlastnyScenarList.txt");
		std::cout << "\n\tCelkovy pocet operacii: ";
		std::cin >> sumOfOperations;
		std::cout << "\n\tPodiel operacii Vloz: ";
		std::cin >> porInsert;
		std::cout << "\n\tPodiel operacii Zrus: ";
		std::cin >> porDelete;
		std::cout << "\n\tPodiel operacii Spristupni/Nastav: ";
		std::cin >> porAccess;
		std::cout << "\n\tPodiel operacii Index prvku: ";
		std::cin >> porSearch;
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		aList->createListScenario(sumOfOperations, porInsert, porDelete, porAccess, porSearch, pList, pFileName);
		std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
		writer.writeData(sumOfOperations);
		writer.writeData("\n");
		writer.writeData(porInsert);
		writer.writeData("\n");
		writer.writeData(porDelete);
		writer.writeData("\n");
		writer.writeData(porAccess);
		writer.writeData("\n");
		writer.writeData(porSearch);
	}
	else if (pScenario == 5) {
		try {
			Input reader("VlastnyScenarList.txt");
			sumOfOperations = reader.readNumber();
			porInsert = reader.readNumber();
			porDelete = reader.readNumber();
			porAccess = reader.readNumber();
			porSearch = reader.readNumber();
			std::cout << "\n\tPREBIEHA TEST...\n" << endl;
			aList->createListScenario(sumOfOperations, porInsert, porDelete, porAccess, porSearch, pList, pFileName);
			std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
		}
		catch (Exception exception) {
			exception.errorMessage2();
		}
	}
	else {
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		aList->test(pScenario, pList, pFileName);
		std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
	}
}

void Tests::callPriorityQueueTest(unsigned int pScenario, structures::PriorityQueue<int>* pQueue, std::string pFileName)
{
	unsigned int sumOfOperations, porPush, porPop, porPeek;

	if (pScenario == 4) {
		Output writer("VlastnyScenarPriorityQueue.txt");
		std::cout << "\n\tCelkovy pocet operacii: ";
		std::cin >> sumOfOperations;
		std::cout << "\n\tPodiel operacii Vloz: ";
		std::cin >> porPush;
		std::cout << "\n\tPodiel operacii Vyber: ";
		std::cin >> porPop;
		std::cout << "\n\tPodiel operacii Ukaz: ";
		std::cin >> porPeek;
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		aQueue->createPriorityQueueScenario(sumOfOperations, porPush, porPop, porPeek, pQueue, pFileName);
		std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
		writer.writeData(sumOfOperations);
		writer.writeData("\n");
		writer.writeData(porPush);
		writer.writeData("\n");
		writer.writeData(porPop);
		writer.writeData("\n");
		writer.writeData(porPeek);
	}
	else if (pScenario == 5) {
		try {
			Input reader("VlastnyScenarPriorityQueue.txt");
			sumOfOperations = reader.readNumber();
			porPush = reader.readNumber();
			porPop = reader.readNumber();
			porPeek = reader.readNumber();
			std::cout << "\n\tPREBIEHA TEST...\n" << endl;
			aQueue->createPriorityQueueScenario(sumOfOperations, porPush, porPop, porPeek, pQueue, pFileName);
			std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
		}
		catch (Exception exception) {
			exception.errorMessage2();
		}
	}
	else {
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		aQueue->test(pScenario, pQueue, pFileName);
		std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
	}
}

void Tests::callMatrixTest(unsigned int pScenario, std::string pFileName)
{
	Output writer(pFileName);
	writer.writeData("Cas;Riadky;Stlpce\n");
	unsigned int counter1 = 1;
	unsigned int counter2 = 1;
	unsigned int counter3 = 1;
	unsigned int m = 0;
	unsigned int n = 0;

	if (pScenario == 1) {
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		for (int i = 0; i < aMatrix->getSumOp(); i++) {
			
			if (i < (aMatrix->getSumOp() / 3)) {
				m = 20 * counter1;
				n = 10 * counter1;
				counter1++;
			}
			else if (i >= (aMatrix->getSumOp() / 3) && i < (aMatrix->getSumOp() - (aMatrix->getSumOp() / 3))) {
				m = 20 * counter3;
				n = 20 * counter3;
				counter3++;
			}
			else {
				m = 10 * counter2;
				n = 20 * counter2;
				counter2++;
			}

			structures::MatrixContinuous<int>* matrix1 = new structures::MatrixContinuous<int>(m, n, 1);
			structures::MatrixContinuous<int>* matrix2 = new structures::MatrixContinuous<int>(m, n, 1);

			unsigned int time = aMatrix->testA(matrix1, matrix2);
			writer.writeData(time);
			writer.writeData(";");
			writer.writeData(m);
			writer.writeData(";");
			writer.writeData(n);
			writer.writeData("\n");

			delete matrix1;
			matrix1 = nullptr;
			delete matrix2;
			matrix2 = nullptr;
		}
	}
	else if (pScenario == 2) {
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		for (int i = 0; i < aMatrix->getSumOp(); i++) {

			if (i < (aMatrix->getSumOp() / 3)) {
				m = 40 * counter1;
				n = 20 * counter1;
				counter1++;
			}
			else if (i >= (aMatrix->getSumOp() / 3) && i < (aMatrix->getSumOp() - (aMatrix->getSumOp() / 3))) {
				m = 40 * counter3;
				n = 40 * counter3;
				counter3++;
			}
			else {
				m = 20 * counter2;
				n = 40 * counter2;
				counter2++;
			}

			structures::MatrixContinuous<int>* matrix1 = new structures::MatrixContinuous<int>(m, n, 1);
			structures::MatrixContinuous<int>* matrix2 = new structures::MatrixContinuous<int>(n, m, 1);

			unsigned int time = aMatrix->testB(matrix1, matrix2);
			writer.writeData(time);
			writer.writeData(";");
			writer.writeData(m);
			writer.writeData(";");
			writer.writeData(n);
			writer.writeData("\n");

			delete matrix1;
			matrix1 = nullptr;
			delete matrix2;
			matrix2 = nullptr;
		}
	}
	else if (pScenario == 3) {
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		for (int i = 0; i < aMatrix->getSumOp(); i++) {

			if (i < (aMatrix->getSumOp() / 3)) {
				m = 20 * counter1;
				n = 10 * counter1;
				counter1++;
			}
			else if (i >= (aMatrix->getSumOp() / 3) && i < (aMatrix->getSumOp() - (aMatrix->getSumOp() / 3))) {
				m = 20 * counter3;
				n = 20 * counter3;
				counter3++;
			}
			else {
				m = 10 * counter2;
				n = 20 * counter2;
				counter2++;
			}

			structures::MatrixDiscontinuous<int>* matrix1 = new structures::MatrixDiscontinuous<int>(m, n, 1);
			structures::MatrixDiscontinuous<int>* matrix2 = new structures::MatrixDiscontinuous<int>(m, n, 1);

			unsigned int time = aMatrix->testA(matrix1, matrix2);
			writer.writeData(time);
			writer.writeData(";");
			writer.writeData(m);
			writer.writeData(";");
			writer.writeData(n);
			writer.writeData("\n");

			delete matrix1;
			matrix1 = nullptr;
			delete matrix2;
			matrix2 = nullptr;
		}
	}
	else if (pScenario == 4) {
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		for (int i = 0; i < aMatrix->getSumOp(); i++) {

			if (i < (aMatrix->getSumOp() / 3)) {
				m = 40 * counter1;
				n = 20 * counter1;
				counter1++;
			}
			else if (i >= (aMatrix->getSumOp() / 3) && i < (aMatrix->getSumOp() - (aMatrix->getSumOp() / 3))) {
				m = 40 * counter3;
				n = 40 * counter3;
				counter3++;
			}
			else {
				m = 20 * counter2;
				n = 40 * counter2;
				counter2++;
			}

			structures::MatrixDiscontinuous<int>* matrix1 = new structures::MatrixDiscontinuous<int>(m, n, 1);
			structures::MatrixDiscontinuous<int>* matrix2 = new structures::MatrixDiscontinuous<int>(n, m, 1);

			unsigned int time = aMatrix->testB(matrix1, matrix2);
			writer.writeData(time);
			writer.writeData(";");
			writer.writeData(m);
			writer.writeData(";");
			writer.writeData(n);
			writer.writeData("\n");

			delete matrix1;
			matrix1 = nullptr;
			delete matrix2;
			matrix2 = nullptr;
		}
	}
	std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
}

void Tests::callBitSetTest(unsigned int pScenario, std::string pFileName)
{
	std::cout << "\n\tPREBIEHA TEST...\n" << endl;
	aBitSet->test(pScenario, pFileName);
	std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
}

void Tests::callTableTest(unsigned int pScenario, structures::Table<int, int>* pTable, std::string pFileName)
{
	unsigned int sumOfOperations, porInsert, porAccess, porDelete;

	if (pScenario == 3) {
		Output writer("VlastnyScenarTable.txt");
		std::cout << "\n\tCelkovy pocet operacii: ";
		std::cin >> sumOfOperations;
		std::cout << "\n\tPodiel operacii Vloz na zaklade kluca: ";
		std::cin >> porInsert;
		std::cout << "\n\tPodiel operacii Spristupni na zaklade kluca: ";
		std::cin >> porAccess;
		std::cout << "\n\tPodiel operacii Odstran na zaklade kluca: ";
		std::cin >> porDelete;
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		aTable->createTableScenario(sumOfOperations, porInsert, porAccess, porDelete, pTable, pFileName);
		std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
		writer.writeData(sumOfOperations);
		writer.writeData("\n");
		writer.writeData(porInsert);
		writer.writeData("\n");
		writer.writeData(porAccess);
		writer.writeData("\n");
		writer.writeData(porDelete);
	}
	else if (pScenario == 4) {
		try {
			Input reader("VlastnyScenarTable.txt");
			sumOfOperations = reader.readNumber();
			porInsert = reader.readNumber();
			porAccess = reader.readNumber();
			porDelete = reader.readNumber();
			std::cout << "\n\tPREBIEHA TEST...\n" << endl;
			aTable->createTableScenario(sumOfOperations, porInsert, porAccess, porDelete, pTable, pFileName);
			std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
		}
		catch (Exception exception) {
			exception.errorMessage2();
		}
	}
	else {
		std::cout << "\n\tPREBIEHA TEST...\n" << endl;
		aTable->test(pScenario, pTable, pFileName);
		std::cout << "\tTEST USPESNE VYKONANY!\n" << endl;
	}
}

void Tests::run()
{
	string pFileName = "";
	int structure, scenario, option = 0;
	bool end = false;

	while (!end) {
		structures::ArrayList<int>* list1 = new structures::ArrayList<int>();
		structures::LinkedList<int>* list2 = new structures::LinkedList<int>();
		structures::DoublyCircularLinkedList<int>* list3 = new structures::DoublyCircularLinkedList<int>();
		structures::PriorityQueueSortedArrayList<int>* queue1 = new structures::PriorityQueueSortedArrayList<int>();
		structures::Heap<int>* queue2 = new structures::Heap<int>();
		structures::PriorityQueueTwoLists<int>* queue3 = new structures::PriorityQueueTwoLists<int>();
		structures::SortedSequenceTable<int, int>* table1 = new structures::SortedSequenceTable<int, int>();
		structures::Treap<int, int>* table2 = new structures::Treap<int, int>();
		structures::HashTable<int, int>* table3 = new structures::HashTable<int, int>();
		structures::BinarySearchTree<int, int>* table4 = new structures::BinarySearchTree<int, int>();

		std::cout << "\t---------------------" << endl;
		std::cout << "\t|    HLAVNE MENU    |" << endl;
		std::cout << "\t---------------------" << endl;
		std::cout << "\n\t[1] Array List" << endl;
		std::cout << "\t[2] Linked List" << endl;
		std::cout << "\t[3] Doubly Circular Linked List" << endl;
		std::cout << "\t[4] Priority Queue Sorted Array List" << endl;
		std::cout << "\t[5] Heap" << endl;
		std::cout << "\t[6] Priority Queue Two Lists" << endl;
		std::cout << "\t[7] Matica v suvislej pamati" << endl;
		std::cout << "\t[8] Matica v nesuvislej pamati" << endl;
		std::cout << "\t[9] Bit Set" << endl;
		std::cout << "\t[10] Sorted Sequence Table" << endl;
		std::cout << "\t[11] Treap" << endl;
		std::cout << "\t[12] Hash Table" << endl;
		std::cout << "\t[13] Binary Search Tree" << endl;
		std::cout << "\n\t[0] Ukoncit" << endl;
		std::cout << "\n\tZvolte strukturu: ";
		std::cin >> structure;
		system("CLS");
		switch (structure) {
		case 1:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Scenar C" << endl;
			std::cout << "\t[4] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[5] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "ArrayListScenarA.csv";
				callListTest(scenario, list1, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "ArrayListScenarB.csv";
				callListTest(scenario, list1, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "ArrayListScenarC.csv";
				callListTest(scenario, list1, pFileName);
			}
			else if (scenario == 4) {
				pFileName = "ArrayListScenarVlastnyVytvor.csv";
				try {
					callListTest(scenario, list1, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 5) {
				pFileName = "ArrayListScenarVlastnyNacitaj.csv";
				callListTest(scenario, list1, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 2:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Scenar C" << endl;
			std::cout << "\t[4] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[5] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "LinkedListScenarA.csv";
				callListTest(scenario, list2, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "LinkedListScenarB.csv";
				callListTest(scenario, list2, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "LinkedListScenarC.csv";
				callListTest(scenario, list2, pFileName);
			}
			else if (scenario == 4) {
				pFileName = "LinkedListScenarVlastnyVytvor.csv";
				try {
					callListTest(scenario, list2, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 5) {
				pFileName = "LinkedListScenarVlastnyNacitaj.csv";
				callListTest(scenario, list2, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 3:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Scenar C" << endl;
			std::cout << "\t[4] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[5] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "DoublyCircularLinkedListScenarA.csv";
				callListTest(scenario, list3, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "DoublyCircularLinkedListScenarB.csv";
				callListTest(scenario, list3, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "DoublyCircularLinkedListScenarC.csv";
				callListTest(scenario, list3, pFileName);
			}
			else if (scenario == 4) {
				pFileName = "DoublyCircularLinkedListScenarVlastnyVytvor.csv";
				try {
					callListTest(scenario, list3, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 5) {
				pFileName = "DoublyCircularLinkedListScenarVlastnyNacitaj.csv";
				callListTest(scenario, list3, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 4:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Scenar C" << endl;
			std::cout << "\t[4] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[5] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "PriorityQueueSortedArrayListA.csv";
				callPriorityQueueTest(scenario, queue1, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "PriorityQueueSortedArrayListB.csv";
				callPriorityQueueTest(scenario, queue1, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "PriorityQueueSortedArrayListC.csv";
				callPriorityQueueTest(scenario, queue1, pFileName);
			}
			else if (scenario == 4) {
				pFileName = "PriorityQueueSortedArrayListVlastnyVytvor.csv";
				try {
					callPriorityQueueTest(scenario, queue1, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 5) {
				pFileName = "PriorityQueueSortedArrayListVlastnyNacitaj.csv";
				callPriorityQueueTest(scenario, queue1, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 5:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Scenar C" << endl;
			std::cout << "\t[4] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[5] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "HeapA.csv";
				callPriorityQueueTest(scenario, queue2, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "HeapB.csv";
				callPriorityQueueTest(scenario, queue2, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "HeapC.csv";
				callPriorityQueueTest(scenario, queue2, pFileName);
			}
			else if (scenario == 4) {
				pFileName = "HeapVlastnyVytvor.csv";
				try {
					callPriorityQueueTest(scenario, queue2, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 5) {
				pFileName = "HeapVlastnyNacitaj.csv";
				callPriorityQueueTest(scenario, queue2, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 6:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Scenar C" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "PriorityQueueTwoListsA.csv";
				std::cout << "\t---------------------" << endl;
				std::cout << "\t|      SCENARE      |" << endl;
				std::cout << "\t---------------------" << endl;
				std::cout << "\n\t[1] Konstantna dlzka" << endl;
				std::cout << "\t[2] Dlzka SQRT(n)" << endl;
				std::cout << "\t[3] Dlzka (n/2)" << endl;
				std::cout << "\n\t[0] Ukoncit" << endl;
				std::cout << "\n\tZvolte scenar: ";
				std::cin >> option;
				if (option == 1) {
					queue3->setInserts((aQueue->getSumOfPush(1) * 1000));
					queue3->setScenario(option);
					callPriorityQueueTest(1, queue3, pFileName);
				}
				else if (option == 2) {
					queue3->setScenario(option);
					callPriorityQueueTest(1, queue3, pFileName);
				}
				else {
					queue3->setScenario(option);
					callPriorityQueueTest(1, queue3, pFileName);
				}
			}
			else if (scenario == 2) {
				pFileName = "PriorityQueueTwoListsB.csv";
				std::cout << "\t---------------------" << endl;
				std::cout << "\t|      SCENARE      |" << endl;
				std::cout << "\t---------------------" << endl;
				std::cout << "\n\t[1] Konstantna dlzka" << endl;
				std::cout << "\t[2] Dlzka SQRT(n)" << endl;
				std::cout << "\t[3] Dlzka (n/2)" << endl;
				std::cout << "\n\t[0] Ukoncit" << endl;
				std::cout << "\n\tZvolte scenar: ";
				std::cin >> option;
				if (option == 1) {
					queue3->setInserts((aQueue->getSumOfPush(2) * 1000));
					queue3->setScenario(option);
					callPriorityQueueTest(2, queue3, pFileName);
				}
				else if (option == 2) {
					queue3->setScenario(option);
					callPriorityQueueTest(2, queue3, pFileName);
				}
				else {
					queue3->setScenario(option);
					callPriorityQueueTest(2, queue3, pFileName);
				}
			}
			else if (scenario == 3) {
				pFileName = "PriorityQueueTwoListsC.csv";
				std::cout << "\t---------------------" << endl;
				std::cout << "\t|      SCENARE      |" << endl;
				std::cout << "\t---------------------" << endl;
				std::cout << "\n\t[1] Konstantna dlzka" << endl;
				std::cout << "\t[2] Dlzka SQRT(n)" << endl;
				std::cout << "\t[3] Dlzka (n/2)" << endl;
				std::cout << "\n\t[0] Ukoncit" << endl;
				std::cout << "\n\tZvolte scenar: ";
				std::cin >> option;
				if (option == 1) {
					queue3->setInserts((aQueue->getSumOfPush(3) * 1000));
					queue3->setScenario(option);
					callPriorityQueueTest(3, queue3, pFileName);
				}
				else if (option == 2) {
					queue3->setScenario(option);
					callPriorityQueueTest(3, queue3, pFileName);
				}
				else {
					queue3->setScenario(option);
					callPriorityQueueTest(3, queue3, pFileName);
				}
			}
			else {
				end = true;
			}
			break;
		case 7:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "MatrixContinuousA.csv";
				callMatrixTest(1, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "MatrixContinuousB.csv";
				callMatrixTest(2, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 8:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "MatrixDiscontinuousA.csv";
				callMatrixTest(3, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "MatrixDiscontinuousB.csv";
				callMatrixTest(4, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 9:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "BitSetA.csv";
				callBitSetTest(scenario, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "BitSetB.csv";
				callBitSetTest(scenario, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 10:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[4] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "SortedSequenceTableScenarA.csv";
				callTableTest(scenario, table1, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "SortedSequenceTableScenarB.csv";
				callTableTest(scenario, table1, pFileName);
			} 
			else if (scenario == 3) {
				pFileName = "SortedSequenceTableVlastnyVytvor.csv";
				try {
					callTableTest(scenario, table1, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 4) {
				pFileName = "SortedSequenceTableVlastnyNacitaj.csv";
				callTableTest(scenario, table1, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 11:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[4] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "TreapScenarA.csv";
				callTableTest(scenario, table2, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "TreapScenarB.csv";
				callTableTest(scenario, table2, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "TreapVlastnyVytvor.csv";
				try {
					callTableTest(scenario, table2, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 4) {
				pFileName = "TreapVlastnyNacitaj.csv";
				callTableTest(scenario, table2, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 12:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[4] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "HashTableScenarA.csv";
				callTableTest(scenario, table3, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "HashTableScenarB.csv";
				callTableTest(scenario, table3, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "HashTableVlastnyVytvor.csv";
				try {
					callTableTest(scenario, table3, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 4) {
				pFileName = "HashTableVlastnyNacitaj.csv";
				callTableTest(scenario, table3, pFileName);
			}
			else {
				end = true;
			}
			break;
		case 13:
			std::cout << "\t---------------------" << endl;
			std::cout << "\t|      SCENARE      |" << endl;
			std::cout << "\t---------------------" << endl;
			std::cout << "\n\t[1] Scenar A" << endl;
			std::cout << "\t[2] Scenar B" << endl;
			std::cout << "\t[3] Vlastny scenar - vytvor" << endl;
			std::cout << "\t[4] Vlastny scenar - nacitaj" << endl;
			std::cout << "\n\t[0] Ukoncit" << endl;
			std::cout << "\n\tZvolte scenar: ";
			std::cin >> scenario;
			system("CLS");
			if (scenario == 1) {
				pFileName = "BinarySearchTreeScenarA.csv";
				callTableTest(scenario, table4, pFileName);
			}
			else if (scenario == 2) {
				pFileName = "BinarySearchTreeScenarB.csv";
				callTableTest(scenario, table4, pFileName);
			}
			else if (scenario == 3) {
				pFileName = "BinarySearchTreeVlastnyVytvor.csv";
				try {
					callTableTest(scenario, table4, pFileName);
				}
				catch (Exception exception) {
					exception.errorMessage1();
				}
			}
			else if (scenario == 4) {
				pFileName = "BinarySearchTreeVlastnyNacitaj.csv";
				callTableTest(scenario, table4, pFileName);
			}
			else {
				end = true;
			}
			break;
		default:
			end = true;
			break;
		}

		delete list1;
		delete list2;
		delete list3;
		delete queue1;
		delete queue2;
		delete queue3;
		delete table1;
		delete table2;
		delete table3;
		delete table4;
		list1 = nullptr;
		list2 = nullptr;
		list3 = nullptr;
		queue1 = nullptr;
		queue2 = nullptr;
		queue3 = nullptr;
		table1 = nullptr;
		table2 = nullptr;
		table3 = nullptr;
		table4 = nullptr;
	}
}

Tests::~Tests()
{
	delete aList;
	aList = nullptr;
	delete aQueue;
	aQueue = nullptr;
	delete aMatrix;
	aMatrix = nullptr;
	delete aBitSet;
	aBitSet = nullptr;
	delete aTable;
	aTable = nullptr;
}


