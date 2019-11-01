#include "pch.h"
#include "Category.h"

Category::Category(json& j) {
	id = j["id"].get<int>();
	categoryName = j["name"].get<string>();
	type = j["type"].get<string>();
	categoryBudget = new Budget(j["budget"]);
}

Category::Category(int categoryId, string name, double budget, string categoryType) {
	id = categoryId;
	categoryName = name;
	categoryBudget = new Budget();
	categoryBudget->setTotal(budget);
	type = categoryType;
}