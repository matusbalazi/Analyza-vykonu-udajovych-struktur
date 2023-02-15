#pragma once
#include <fstream>
#include <cstring>
#include <iomanip>
#include "structures/heap_monitor.h"

using namespace std;

class Output
{
private:
	string aFileName;
	std::ofstream aFile;
public:
	Output(string pFileName);
	void writeText(string pText);
	void writeNumber(double pNumber);
	void writeInt(unsigned int pNumber);

	template<typename T>
	void writeData(T pData);

	~Output();
};

template<typename T>
inline void Output::writeData(T pData)
{
	if (aFile.is_open()) {
		aFile << pData;
	}
}
