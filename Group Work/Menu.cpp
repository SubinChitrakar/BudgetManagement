#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;


void Menu::startMenu() {
	int menuChoice;
	cout << ">> Menu" <<endl;

	cout << "1. Transaction" << endl;
	cout << "2. Category  " << endl;
	cout << "3. Report " << endl;

	cout << "\n \t Enter your choice: ";
	cin >> menuChoice;

	cout << endl <<endl;

	switch (menuChoice) {
	case 1: "Transaction";
		break;
	case 2: 
		categoryController.setCategoryList(dc->convertToCategory());
		categoryController.categoryFunctionMenu(dc);
		break;
	case 3: "Report";
		break;
	default: cout << "THE VALUE YOU HAVE ENTERED IS INCORRECT.!!!!!!" << endl << endl;
	}
	
	startMenu();
}

