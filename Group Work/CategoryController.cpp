#include "pch.h"
#include "CategoryController.h"
#include <sstream>
#include "ConsoleIO.h"

void CategoryController::categoryFunctionMenu() {
	
	//clears console
	system("CLS");


	int option = 0;
	viewCategoryList();
	cout << "ENTER THE FUNCTIONALITY YOU WANT TO CONTINUE.."<<endl;
	cout << "\t 1. Add a new Categories" << endl;
	cout << "\t 2. Edit a Category" << endl;
	cout << "\t 3. Delete a Category" << endl;
	cout << "\t 4. Go back to the Menu" << endl;
	cout << "\t ENTER THE NO. OF THE FUNCTION(1-4): \t";
	cin >> option;
	cout << endl << endl;
	switch (option) {
	case 1: addCategory();
		break;
	case 2: editCategory();
		break;
	case 3: deleteCategory();
		break;
	case 4: cout << "\t BACK TO MAIN MENU" << endl;
		break;
	default: cout << "\t THE VALUE YOU HAVE ENTERED IS INCORRECT.!!!!!!"<<endl <<endl;
		categoryFunctionMenu();
	}

}


void CategoryController::viewCategoryList() {
	cout << "LIST OF CATEGORY" << endl;
	int count = 1;
	for (Category& category : categoryList)
	{
		cout << "\t  " << count << ". " << category.getCategoryName() << "\t \t" << category.getCategoryBudget()->getTotal() << endl;
		count++;
	}
	cout << endl << endl;
}


void CategoryController::addCategory() {
	//Clears console//
	system("CLS");

	string categoryName;
	double budget;
	int categoryValue;
	string categoryType;
	bool status = true;

	categoryName=ConsoleIO::in("\t \t \t ADD CATEGORY \n Enter the name of the category:");
	cout << endl;
	
	budget = stod(ConsoleIO::in("Enter the budget of the category: ", AMOUNT));
	cout << endl;

	system("CLS");

	do {
		cout << "\t 1. Income" << endl;
		cout << "\t 2. Expense" << endl;
		cout << "Enter the type of the category(1 or 2): \t";
		cin >> categoryValue;
		
		if (categoryValue == 1 || categoryValue == 2)
		{
			status = false;
		}
	} while (status);
	categoryValue == 1 ? categoryType = "Income" : categoryType = "Expense";

	categoryList.push_back(Category(categoryList.back().getId() + 1, categoryName, budget, categoryType));

	categoryFunctionMenu();
}


void CategoryController::editCategory() {
	int option;
	bool status = true;
	do {
		cout << "\t \t \t EDIT CATEGORY" << endl;
		cout << "\tEnter the number of the category you want to edit: \t";
		cin >> option;
		option -= 1;

		if (option >= 0 && option < categoryList.size())
		{
			status = false;
		}
		else {
			cout << endl << endl;
			cout << "\tTHE CATEGORY NUMBER DOES NOT EXIST. \t" << endl;
		}

	} while (status);

	Category editedCategory = categoryList.at(option);
	string categoryName;
	string budgetValue;
	int categoryValue;
	bool categoryStatus = true; 

	categoryName = ConsoleIO::in("\t \t      EDIT CATEGORY \nCategory Name: " + editedCategory.getCategoryName() + "\nNew Category Name (Press return to not change the value): ", TEXT, 100, true);
	if (categoryName.size() > 0){
		editedCategory.setCategoryName(categoryName);
	}

	budgetValue = ConsoleIO::in("\tBudget: " + to_string(editedCategory.getCategoryBudget()->getTotal()) + "\nNew Budget (Press return to not change the value): ", AMOUNT, 100, true);
	if (budgetValue.size() > 0) {
		editedCategory.getCategoryBudget()->setTotal(stod(budgetValue));
	}

	system("CLS");

	cout << "Category Type: " << editedCategory.getType() << endl;
	cout << "New Category Type: "<<endl;
	do {
		cout << "\t 1. Income" << endl;
		cout << "\t 2. Expense" << endl;
		cout << "\t 3. No Change" << endl;
		cout << "\t Enter the type of the category(1 or 2 or 3): \t";
		cin >> categoryValue;

		if (categoryValue == 1 || categoryValue == 2 || categoryValue == 3)
		{
			categoryStatus = false;
		}
	} while (categoryStatus);

	categoryValue == 1 ? editedCategory.getType() = "Income" : editedCategory.getType() = editedCategory.getType();
	categoryValue == 2 ? editedCategory.getType() = "Expense" : editedCategory.getType() = editedCategory.getType();

	categoryList.at(option) = editedCategory;
	categoryFunctionMenu();
}

void CategoryController::deleteCategory() {
	int option;
	bool status = true;
	do {
		cout << "\t \t \t DELETE CATEGORY" << endl;
		cout << "\tEnter the number of the category you want to delete: \t";
		cin >> option;
		option -= 1;

		if (option >= 0 && option < categoryList.size())
		{
			status = false;
		}
		else {
			cout << endl << endl;
			cout << "\tTHE CATEGORY NUMBER DOES NOT EXIST. \t"<<endl;
		}
		
	} while (status);

	categoryList.erase(categoryList.begin() + option);

	categoryFunctionMenu();
}

