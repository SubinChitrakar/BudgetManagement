#include "pch.h"
#include "User.h"
#include "Category.h"
#include "DataConverter.h"
#include<iostream>

using namespace std;

vector<Category> DataConverter::convertToClass(json& j) {
	vector<Category> cat = {};
	for (json::iterator it = j["categories"].begin(); it != j["categories"].end(); ++it) {
		cat.push_back(Category(*it));
	}
	return cat;
}