#pragma once
#include "Transaction.h"
#include "Time.h"
#include "json.hpp"

using nlohmann::json;

class NormalTransaction : public Transaction
{
private:
	string date;
	string time;
public:
	NormalTransaction() : Transaction() {};
	NormalTransaction(json& j, Category& c);
	NormalTransaction(int id, string name, double amount, Category cat, string note, string date, string time);
	string getTime() { return time; }
	void setTime(string _time) { time = _time; }
	string getDate() { return date; }
	void setDate(string _date) {date = _date;}
	json getNormalTransaction();
};

