#include "Category.h"
#include <iostream>
#include "string"
#include "DataConverter.h"

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

	vector<Category> getCategoryList() {
		return categoryList;
	}

	void categoryFunctionMenu(DataConverter* dc);
	void viewCategoryList();
	void addCategory();
	void editCategory();
	void deleteCategory();
};

