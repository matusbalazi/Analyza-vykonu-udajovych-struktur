#pragma once
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Exception.h"
#include "structures/heap_monitor.h"

using namespace std;

class Input
{
private:
	string aFileName;
	ifstream aFile;
public:
	Input(string pFileName);

	string readText();
	unsigned int readNumber();

	template<typename T>
	T readData();

	~Input();
};

template<typename T>
inline T Input::readData()
{
	T data = nullptr;

	if (aFile.is_open()) {
		aFile >> data;
		return data;
	}

	return nullptr;
}
