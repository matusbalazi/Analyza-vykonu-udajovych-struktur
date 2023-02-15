#pragma once
#include <iostream>
#include "structures/heap_monitor.h"

using namespace std;

class Exception 
{
public:
	void errorMessage1() 
	{
		cout << "\t---------------------------------------------" << endl;
		cout << "\t|            AKCIA ZAMIETNUTA!!!            |" << endl;
		cout << "\t|        NESPRAVNE ZADANE HODNOTY!!!        |" << endl;
		cout << "\t---------------------------------------------\n" << endl;
	}
	void errorMessage2()
	{
		cout << "\t---------------------------------------------" << endl;
		cout << "\t|         NEMOZNO NACITAT HODNOTY!!!        |" << endl;
		cout << "\t|       SCENAR ESTE NEBOL VYTVORENY!!!      |" << endl;
		cout << "\t---------------------------------------------\n" << endl;
	}
};