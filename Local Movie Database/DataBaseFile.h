#pragma once
#include "DataBase.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include <assert.h>
#include <iostream>

class DataBaseFile : public DataBase
{
public:
	DataBaseFile();
	virtual ~DataBaseFile() {}
	void setFileName(const std::string& filename);
	virtual void write() = 0;
	virtual void show() = 0;
protected:
	std::string filename;
};

