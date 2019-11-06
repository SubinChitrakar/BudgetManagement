#pragma once
#include <iostream>
#include "string"
#include "Transaction.h"
#include "json.hpp"
#include "RepeatType.h"

using nlohmann::json;

using namespace std;

class RecurringTransaction : public Transaction
{
private:
	string date;
	string time;
	RepeatTypes repeat;
public:
	RecurringTransaction() : Transaction() {};
	RecurringTransaction(json& j, Category& c);
	RecurringTransaction(int id, string name, double amount, Category cat, string note, RepeatTypes r, string date, string time);
	json getRecurringTransaction();
	void setRepeat(RepeatTypes r) { repeat = r; };
	RepeatTypes getRepeat() { return repeat; }
	string getTime() { return time; }
	void setTime(string _time) { time = _time; }
	string getDate() { return date; }
	void setDate(string _date) { date = _date; }
};

