#pragma once
#include "DataBaseFile.h"
#include <string>

class CSVFILE :public DataBaseFile
{
public:
	void write() override;
	void show() override;
};