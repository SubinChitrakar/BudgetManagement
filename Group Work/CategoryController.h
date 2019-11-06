#pragma once
#include "Category.h"
#include <iostream>
#include <sstream>
#include "string"
#include "DataConverter.h"
#include "ConsoleIO.h"
#include "CppConsoleTable.hpp"

#define _CRT_SECURE_NO_WARNINGS

using ConsoleTable = samilton::ConsoleTable;

class CategoryController
{
private:
	vector<Category> categoryList;
public:
	void setCategoryList(vector<Category> JSONCategoryList) {
		if (categoryList.size() == 0)
		{
			categoryList = JSONCategoryList;
		}
	}

	vector<Category>& getCategoryList() {
		return categoryList;
	}

	void categoryFunctionMenu(DataConverter* dc);
	void viewCategoryList();
	void addCategory();
	void editCategory();
	void deleteCategory();
};

