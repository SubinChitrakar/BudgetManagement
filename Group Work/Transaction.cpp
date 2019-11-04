#include "pch.h"
#include "Transaction.h"

Transaction::Transaction(int id, string name, double amount, Category* cat, string note) {
	id = id;
	transactionName = name;
	amount = amount;
	category = cat;
	note = note;
}
