#include "pch.h"
#include "Transaction.h"

Transaction::Transaction(json& j) {
	id = j["id"].get<int>();
	transactionName = j["name"].get<string>();
	note = j["note"].get<string>();
	amount = j["amount"].get<double>();
}

Transaction::Transaction(int _id, string name, double _amount, Category* cat, string _note) {
	id = _id;
	transactionName = name;
	amount = _amount;
	category = cat;
	note = _note;
}
