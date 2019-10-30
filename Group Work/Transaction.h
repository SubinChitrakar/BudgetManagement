#pragma once
#include "Category.h"
#include <string>
using namespace std;

class Transaction
{
private:
	int id;
	string transactionName;
	float amount;
	Category category;
	string note;

public:
	int getId() { return id; }
	string getTransactionName() { return transactionName; }
	float getAmount() { return amount; }
	Category getCategory() { return category; }
	string getNote() { return note; }

	void setId(int _id) { id = _id; }
	void settransactionName(string _transactionName) { transactionName = _transactionName; }
	void setAmount(float _amount) { amount = _amount; }
	void setCategory(Category _category) { category = _category; }
	void setNote(string _note) { note = _note; }





};

