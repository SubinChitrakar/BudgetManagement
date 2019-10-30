#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include "CppConsoleTable.hpp"

using namespace std;

//using this for console table
using ConsoleTable = samilton::ConsoleTable;

void Menu::header() {
	cout << "\t******************BUDGET MANAGEMENT SYSTEM****************** \n \n";
	cout << "\t \t \t \t B M S C++\n \n";
}

void Menu::footer() {
	cout << "\n \t************************************************************ \n \n";
}

void Menu::displayIntro() {

	header();
	string username, password;

	cout << "\t \t   >> Please Enter your Credentials to login \n \n";

	cout << "\t \t     Username: \t";
	cin >> username;

	cout << "\n \t \t     Password: \t";
	cin >> password;

	footer();
}

void Menu::startMenu() {
	header();

	int menuChoice;
	cout << "\t \t     >> Menu \n \n";

	cout << "\t \t \t     1. Transaction" << endl;
	cout << "\t \t \t     2. Category  " << endl;
	cout << "\t \t \t     3. Report " << endl;

	cout << "\n \t \t \t Enter your choice: ";
	cin >> menuChoice;

	footer();
}

