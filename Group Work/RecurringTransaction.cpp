#include "pch.h"
#include "RecurringTransaction.h"

RecurringTransaction::RecurringTransaction(json& j, Category & c) : Transaction(j)
{
	setId(j["id"].get<int>());
	setTransactionName(j["name"].get<string>());
	setAmount(j["amount"].get<double>());
	setNote(j["note"].get<string>());
	setCategory(&c);
	date = j["date"].get<string>();
	time = j["time"].get<string>();
	repeat = RepeatTypes(j["repeat"].get<int>());
}

RecurringTransaction::RecurringTransaction(int id, string name, double amount, Category cat, string note, RepeatTypes r, string date, string time) : Transaction(id, name, amount, &cat, note)
{
	repeat = r;
}

json RecurringTransaction::getRecurringTransaction()
{
	json j;
	j["id"] = getId();
	j["name"] = getTransactionName();;
	j["amount"] = getAmount();
	j["note"] = getNote();
	j["category"] = getCategory()->getId();
	j["date"] = date;
	j["time"] = time;
	j["repeat"] = repeat;
	return j;
}
