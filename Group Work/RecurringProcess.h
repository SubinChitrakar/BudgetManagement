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
public:
	void runProcess(DataConverter* dc, vector<RecurringTransaction>& rtr, vector<NormalTransaction>& ntr, vector<Category>& cat);
};

