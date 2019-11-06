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

	recurringProcess.runProcess(dc, &transactionController.getRecurringTransactionList(), &transactionController.getNormalTransactionList(), &categoryController.getCategoryList());

	ConsoleIO::out("MAIN MENU:\n1. Transaction\n2. Category\n3. Report\n4. Quit", true);
	string out = "Please, choose menu item:";

	menuChoice = stoi(ConsoleIO::in(out, NUMBER, 1));

	switch (menuChoice) {
	case 1:
		transactionController.transactionFunctionMenu(dc, categoryController.getCategoryList());
		break;
	case 2: 
		categoryController.categoryFunctionMenu(dc);
		break;
	case 3:
		reportController.reportFunctionMenu(dc, categoryController.getCategoryList(), transactionController.getNormalTransactionList());
		break;
	case 4:
		exit(0);
		break;
	}
	startMenu();
}

