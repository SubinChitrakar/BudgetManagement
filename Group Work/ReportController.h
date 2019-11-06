#pragma once
#include <iostream>
#include "string"
#include "CppConsoleTable.hpp"
#include "DataConverter.h"
#include "ConsoleIO.h"
#include "Time.h"

#define _CRT_SECURE_NO_WARNINGS

using ConsoleTable = samilton::ConsoleTable;
using namespace std;

class ReportController
{
private:
	int month = 0;
	int year = 0;
	Time* filter;
	Time* each;
	void addMonth(int plus = 0);
	void addYear(int plus = 0);
	void showReport(DataConverter * dc, vector<Category>& cat, vector<NormalTransaction>& ntr);
public:
	void reportFunctionMenu(DataConverter* dc, vector<Category>& cat, vector<NormalTransaction>& ntr);
};

