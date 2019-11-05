#include "pch.h"
#include "NormalTransaction.h"

NormalTransaction::NormalTransaction(json& j, Category& c) : Transaction(j) {
	setId(j["id"].get<int>());
	setTransactionName(j["name"].get<string>());
	setAmount(j["amount"].get<double>());
	setNote(j["note"].get<string>());
	setCategory(&c);
	date = j["date"].get<string>();
	time = j["time"].get<string>();
}

NormalTransaction::NormalTransaction(int id, string name, double amount, Category cat, string note, string idate, string itime) : Transaction(id, name, amount, &cat, note){
	time = itime;
	date = idate;
}

json NormalTransaction::getNormalTransaction() {
	json j;
	j["id"] = getId();
	j["name"] = getTransactionName();;
	j["amount"] = getAmount();
	j["note"] = getNote();
	j["category"] = getCategory()->getId();
	j["date"] = date;
	j["time"] = time;
	return j;
}