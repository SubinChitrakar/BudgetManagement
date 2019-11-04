#pragma once
#include <string>
#include "json.hpp"

using nlohmann::json;
using namespace std;

class Category
{ 
private:
	int id;
	string categoryName;
	string type;
	double limit;
public:
	Category(json& j);
	Category(int categoryId,string name, double budget, string categoryType);
	json getCategory();
	int getId() { return id;  }
	string getCategoryName() { return categoryName; }
	string getType() { return type; }
	void setCategoryName(string _categoryName) { categoryName = _categoryName; }
	void setType(string _type) { type = _type; }
	double getLimit() { return limit; }
	void setLimit(double categoryLimit) { limit = categoryLimit; }
};

