#include "Category.h"
#include <iostream>
#include "string"


class CategoryController
{
private:
	vector<Category> categoryList;
public:
	void setCategoryList(vector<Category> JSONCategoryList) {
		categoryList = JSONCategoryList;
	}

	vector<Category> getCategoryList() {
		return categoryList;
	}

	void categoryFunctionMenu();
	void viewCategoryList();
	void addCategory();
	void editCategory();
	void deleteCategory();
};

