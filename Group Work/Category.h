#pragma once
#include <string>
#include "Budget.h"

using namespace std;

class Category
{ 
private:
	string categoryName;
	Budget categoryBudget;
	string status;

public:
	string getCategoryName() { return categoryName; }
	Budget getCategoryBudget() { return categoryBudget; }
	string getstatus() { return status; }
	void setCategoryName(string _categoryName) { categoryName = _categoryName; }
	void setCategoryBudget(Budget _categoryBudget) { categoryBudget = _categoryBudget; }
	void setStatus(string _status) { status = _status; }

};

