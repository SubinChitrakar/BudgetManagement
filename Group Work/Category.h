#pragma once
#include <string>
#include "Budget.h"
#include "json.hpp"

using nlohmann::json;
using namespace std;

class Category
{ 
private:
	string categoryName;
	Budget* categoryBudget;
	string type;
public:
	Category(json& j);
	string getCategoryName() { return categoryName; }
	Budget getCategoryBudget() { return *categoryBudget; }
	string getType() { return type; }
	void setCategoryName(string _categoryName) { categoryName = _categoryName; }
	void setCategoryBudget(Budget *_categoryBudget) { categoryBudget = _categoryBudget; }
	void setType(string _type) { type = _type; }
};

