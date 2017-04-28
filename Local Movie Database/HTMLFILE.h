#pragma once
#include "DataBaseFile.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include <assert.h>
#include <iostream>
#include <Windows.h>


class HTMLFILE :public DataBaseFile
{
public:
		void write() override;
		void show() override;
};