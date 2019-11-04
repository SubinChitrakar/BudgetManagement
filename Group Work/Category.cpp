#include "pch.h"
#include "Category.h"

Category::Category(json& j) {
	id = j["id"].get<int>();
	categoryName = j["name"].get<string>();
	type = j["type"].get<string>();
	limit = j["limit"].get<double>();
}

Category::Category(int categoryId, string name, double categoryLimit, string categoryType) {
	id = categoryId;
	categoryName = name;
	type = categoryType;
	limit = categoryLimit;
}

json Category::getCategory() {
	json j;
	j["id"] = id;
	j["name"] = categoryName;
	j["type"] = type;
	j["limit"] = limit;
	return j;
}