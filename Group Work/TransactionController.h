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
	void viewTransactionList();
	void addTransaction(vector<Category>& cat);
	void editTransaction();
	void deleteTransaction();
	void getNormalTransactionInput(Transaction& tr, string& info);
public:
	void setNormalTransactionList(vector<NormalTransaction> JSONTransactionList) {
		if (normalTransactionList.size() == 0)
		{
			normalTransactionList = JSONTransactionList;
		}
	}

	vector<NormalTransaction> getNormalTransactionList() {
		return normalTransactionList;
	}

	void transactionFunctionMenu(DataConverter* dc, vector<Category>& cat);
};

