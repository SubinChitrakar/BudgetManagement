#pragma once
#include "Transaction.h"
#include "Category.h"
#include "CategoryController.h"
#include <iostream>
#include "string"


class TransactionController
{
private:
	vector<Transaction> transactionList;
public:
	void setTransactionList(vector<Transaction> JSONTransactionList) {
		transactionList = JSONTransactionList;
	}

	vector<Transaction> getTransactionList() {
		return transactionList;
	}

	void transactionFunctionMenu();
	void viewTransactionList();
	void addTransaction();
	void editTransaction();
	void deleteTransaction();
};

