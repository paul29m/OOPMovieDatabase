#include "CSVFILE.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include <assert.h>
#include <iostream>
#include <Windows.h>

using namespace std;

void CSVFILE::write() {
	ofstream file(this->filename);
	if (this->isData())
	{
		file << " ";
		file.close();
		return;
	}
	std::string fileName = "";
	for (auto v : this->list)
		fileName = fileName + "\n" + v.movieFileName();
	file << fileName;
	file.close();

}


void CSVFILE::show() {
	ShellExecuteA(NULL, NULL, "notepad.exe", this->filename.c_str(), NULL, SW_MAXIMIZE);
}