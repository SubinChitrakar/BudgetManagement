#include "pch.h"
#include "DataConverter.h"

using namespace std;

vector<Category> DataConverter::convertToCategory() {
	vector<Category> cat = {};
	for (json::iterator it = j["categories"].begin(); it != j["categories"].end(); ++it) {
		cat.push_back(Category(*it));
	}
	return cat;
}

void DataConverter::convertFromCategory(vector<Category> categoryList) {
	j["categories"].clear();
	for (auto i = categoryList.begin(); i != categoryList.end(); ++i) {
		j["categories"].push_back((*i).getCategory());
	}
	saveData();
}