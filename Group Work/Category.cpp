#include "pch.h"
#include "Category.h"

Category::Category(json& j) {
	categoryName = j["name"].get<string>();
	type = j["type"].get<string>();
	categoryBudget = new Budget(j["budget"]);
}