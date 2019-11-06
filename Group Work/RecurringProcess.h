#pragma once
#include <iostream>
#include <string>
#include "DataConverter.h"
#include "Time.h"
#include "Category.h"
#include "RecurringProcess.h"
#include "NormalTransaction.h"

class RecurringProcess
{
private:
	int getCount(int year);
	int getDifference(int d1, int m1, int y1, int d2, int m2, int y2);
public:
	void runProcess(DataConverter* dc, vector<RecurringTransaction>& rtr, vector<NormalTransaction>& ntr, vector<Category>& cat);
};

