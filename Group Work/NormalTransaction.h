#pragma once
#include "Transaction.h"
#include "Time.h"

class NormalTransaction : public Transaction
{
private:
	Time* time;

public:
	NormalTransaction(int id, string name, double amount, Category* cat, string note, Time* time);
	Time* getTime() { return time; }
	void setTime(Time* _time) { time = _time; }
};

