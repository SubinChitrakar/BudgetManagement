#pragma once
#include "Category.h"
#include <string>
using namespace std;

class Transaction
{
private:
	int id;
	string transactionName;
	double amount;
	Category* category;
	string note;

public:
	Transaction(int id, string name, double amount, Category* cat, string note);
	int getId() { return id; }
	string getTransactionName() { return transactionName; }
	double getAmount() { return amount; }
	Category* getCategory() { return category; }
	string getNote() { return note; }

	void setId(int _id) { id = _id; }
	void settransactionName(string _transactionName) { transactionName = _transactionName; }
	void setAmount(double _amount) { amount = _amount; }
	void setCategory(Category* _category) { category = _category; }
	void setNote(string _note) { note = _note; }

};

