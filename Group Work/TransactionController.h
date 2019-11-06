#pragma once
#include "NormalTransaction.h"
#include <iostream>
#include "string"
#include "DataConverter.h"
#include "ConsoleIO.h"
#include "CppConsoleTable.hpp"

#define _CRT_SECURE_NO_WARNINGS

using ConsoleTable = samilton::ConsoleTable;

class TransactionController
{
private:
	vector<NormalTransaction> normalTransactionList;
	vector<RecurringTransaction> recurringTransactionList;
	void viewNormalTransactionList();
	void viewRecurringTransactionList();
	void addTransaction(vector<Category>& cat);
	void editTransaction(vector<Category>& cat);
	void deleteNormalTransaction();
	void deleteRecurringTransaction();
	string getRecurringTransactionInput(NormalTransaction& tr, string& info);
public:
	void setNormalTransactionList(vector<NormalTransaction> JSONTransactionList) {
		if (normalTransactionList.size() == 0)
		{
			normalTransactionList = JSONTransactionList;
		}
	}
	
	void setRecurringTransactionList(vector<RecurringTransaction> JSONTransactionList) {
		if (recurringTransactionList.size() == 0)
		{
			recurringTransactionList = JSONTransactionList;
		}
	}

	vector<NormalTransaction>& getNormalTransactionList() { return normalTransactionList; }
	vector<RecurringTransaction>& getRecurringTransactionList() { return recurringTransactionList; }

	void transactionFunctionMenu(DataConverter* dc, vector<Category>& cat);
};

