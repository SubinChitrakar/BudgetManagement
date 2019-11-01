#pragma once
#include <string>
#include "Budget.h"
#include "json.hpp"

using nlohmann::json;
using namespace std;

class Category
{ 
private:
	int id;
	string categoryName;
	Budget* categoryBudget;
	string type;
public:
	Category(json& j);
	Category(int categoryId,string name, double budget, string categoryType);
	int getId() { return id;  }
	string getCategoryName() { return categoryName; }
	Budget* getCategoryBudget() { return categoryBudget; }
	string getType() { return type; }
	void setCategoryName(string _categoryName) { categoryName = _categoryName; }
	void setCategoryBudget(Budget *_categoryBudget) { categoryBudget = _categoryBudget; }
	void setType(string _type) { type = _type; }
};

