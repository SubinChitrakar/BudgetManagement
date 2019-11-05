#include "pch.h"
#include "CategoryController.h"

void CategoryController::categoryFunctionMenu(DataConverter* dc) {

	int option = 0;

	viewCategoryList();

	ConsoleIO::out("1.Add   2.Edit   3.Delete   4.Go back\n");

	option = stoi(ConsoleIO::in("Please, choose menu item to continue:", NUMBER, 1));

	switch (option) {
	case 1: addCategory();
			break;
	case 2: editCategory();
			break;
	case 3: deleteCategory();
			break;
	case 4:return;
			break;
	}

	dc->convertFromCategory(getCategoryList());
	categoryFunctionMenu(dc);

}


void CategoryController::viewCategoryList() {
	ConsoleTable table(samilton::Alignment::centre);

	table.setIndent(1, 1);
	
	table[0][0] = "#";
	table[0][1] = "Name";
	table[0][2] = "Amount (GBP/per month)";
	table[0][3] = "Type";

	ConsoleIO::out({}, true);
	int count = 1;
	for (Category& category : categoryList)
	{
		table[count][0] = to_string(count);
		table[count][1] = category.getCategoryName();
		table[count][2] = ConsoleIO::dbl(category.getLimit());
		table[count][3] = category.getType();
		count++;
	}
	cout << table;
}


void CategoryController::addCategory() {
	string categoryName;
	double limit;
	string categoryType;
	bool status = true;

	string info = "ADD CATEGORY\nPress ESC button to cancel the operation.\n";

	ConsoleIO::out(info, true);
	categoryName=ConsoleIO::in("Please, enter category name:", TEXT, 100, false, false, true);
	if (categoryName == " ") return;

	ConsoleIO::out(info, true);
	string limitIn = ConsoleIO::in("Enter the budget limit for the category: ", AMOUNT, 8, false, false, true);
	if (limitIn == " ") return;
	else limit = stod(limitIn);

	do {
		ConsoleIO::out(info, true);
		string typeIn = ConsoleIO::in("Please, choose category type:\n1.Income\n2.Expense", NUMBER, 1, false, false, true);
		if (typeIn == " ") return;
		else {
			int catVal = stoi(typeIn);
			if (catVal == 1 || catVal == 2) {
				catVal == 1 ? categoryType = "Income" : categoryType = "Expense";
				status = false;
			}
		}
	} while (status);

	if (status) return;

	int id = (categoryList.size() > 0) ? categoryList.back().getId() + 1 : 1;

	categoryList.push_back(Category(id, categoryName, limit, categoryType));
}


void CategoryController::editCategory() {
	int option;
	bool status = true;
	string info = "EDIT CATEGORY";
	string info_2 = "\nPress ESC to cancel the operation.\n";

	do {
		viewCategoryList();
		ConsoleIO::out("\n" + info + info_2);
		string numIn = ConsoleIO::in("Please, enter the number of category:", NUMBER, 3, false, false, true);

		if (numIn == " ") return;

		option = stoi(numIn) - 1;

		if (option >= 0 && option < categoryList.size()) status = false;

	} while (status);

	Category editedCategory = categoryList.at(option);
	string categoryName;
	string budgetValue;
	bool categoryStatus = true; 

	ConsoleIO::out(info + ": " + editedCategory.getCategoryName() + info_2, true);

	categoryName = ConsoleIO::in("Please, enter category name (press Enter to leave current name): ", TEXT, 100, true, false, true);
	if (categoryName == " ") return;
	if (categoryName.size() > 0){
		editedCategory.setCategoryName(categoryName);
	}

	ConsoleIO::out(info + ": " + editedCategory.getCategoryName() + info_2, true);
	budgetValue = ConsoleIO::in("Current budget limit: " + ConsoleIO::dbl(editedCategory.getLimit()) + "\nPlease, enter new amount (press Enter to leave current amount): ", AMOUNT, 8, true, false, true);
	if (budgetValue == " ") return;
	if (budgetValue.size() > 0) {
		editedCategory.setLimit(stod(budgetValue));
	}

	do {
		ConsoleIO::out(info + ": " + editedCategory.getCategoryName() + info_2, true);
		string typeIn = ConsoleIO::in("Please, choose category type (press Enter to leave current type):\n1.Income\n2.Expense", NUMBER, 1, true, false, true);
		if (typeIn == " ") return;
		else if (typeIn.size() > 0) {
			int catVal = stoi(typeIn);
			if (catVal == 1 || catVal == 2) {
				editedCategory.setType((catVal == 1) ? "Income" : "Expense");
				categoryStatus = false;
			}
		}
		else if (typeIn.size() == 0) categoryStatus = false;
	} while (categoryStatus);

	categoryList.at(option) = editedCategory;
}

void CategoryController::deleteCategory() {
	int option;
	bool status = true;
	string info = "DELETE CATEGORY\nPress ESC to cancel the operation.\n";
	do {
		viewCategoryList();
		ConsoleIO::out("\n" + info);
		string numIn = ConsoleIO::in("Please, enter the number of category:", NUMBER, 3, false, false, true);
		if (numIn == " ") return;
		option = stoi(numIn) - 1;

		if (option >= 0 && option < categoryList.size()) status = false;

	} while (status);

	categoryList.erase(categoryList.begin() + option);
}

