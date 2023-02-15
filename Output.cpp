#include "Output.h"
#include "structures/heap_monitor.h"

Output::Output(string pFileName) :
	aFileName(pFileName)
{
	aFile.open(aFileName);
}

void Output::writeText(string pText)
{
	if (aFile.is_open()) {
		aFile << pText;
	}
}


void Output::writeNumber(double pNumber)
{
	if (aFile.is_open()) {
		aFile << fixed << setprecision(5) << pNumber;
	}
}

void Output::writeInt(unsigned int pNumber)
{
	if (aFile.is_open()) {
		aFile << pNumber;
	}
}

Output::~Output()
{
	if (aFile.is_open()) {
		aFile.close();
	}
}
