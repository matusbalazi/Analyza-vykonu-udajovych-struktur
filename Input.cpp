#include "Input.h"
#include "structures/heap_monitor.h"

Input::Input(string pFileName) :
	aFileName(pFileName)
{
	aFile.open(aFileName);
}

string Input::readText()
{
	string data = "";

	if (aFile.is_open()) {
		aFile >> data;
		return data;
	}

	return "";
}

unsigned int Input::readNumber()
{
	unsigned int data = 0;

	if (aFile.is_open()) {
		if (aFile >> data) {
			return data;
		}
		else {
			throw Exception();
		}
	}
	return 0;
}

Input::~Input()
{
	if (aFile.is_open()) {
		aFile.close();
	}
}
