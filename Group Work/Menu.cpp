#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;


void Menu::startMenu() {
	int menuChoice;

	categoryController.setCategoryList(dc->convertToCategory());
	transactionController.setNormalTransactionList(dc->convertToNormalTransaction(categoryController.getCategoryList()));
	transactionController.setRecurringTransactionList(dc->convertToRecurringTransaction(categoryController.getCategoryList()));

	ConsoleIO::out("MENU:\n1. Transaction\n2. Category\n3. Report\n", true);
	string out = "Please, choose menu item:";

	menuChoice = stoi(ConsoleIO::in(out, NUMBER, 1));

	switch (menuChoice) {
	case 1:
		transactionController.transactionFunctionMenu(dc, categoryController.getCategoryList());
		break;
	case 2: 
		categoryController.categoryFunctionMenu(dc);
		break;
	case 3: // Report
		break;
	}
	startMenu();
}

