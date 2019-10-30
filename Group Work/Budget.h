#pragma once

class Budget
{
private:
	double income = 0;
	double spending = 0;
public:
	double getIncome() { return income; }
	double getSpending() { return spending; }
	void addIncome(double _income) { income += _income; }
	void addSpending(double _spending) { spending += _spending; }
	void removeIncome(double _income) { income -= _income; }
	void removeSpending(double _spending) { spending -= _spending; }
};