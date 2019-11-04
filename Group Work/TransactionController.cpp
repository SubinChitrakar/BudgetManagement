#include "pch.h"
#include "TransactionController.h"
#include "NormalTransaction.h"
#include "ConsoleIO.h"

void TransactionController::transactionFunctionMenu(){
	//clears console
	system("CLS");

	int option = 0;
	viewTransactionList();
	cout << "ENTER THE FUNCTIONALITY YOU WANT TO CONTINUE.." << endl;
	cout << "\t 1. Add a new Transaction" << endl;
	cout << "\t 2. Edit a Transaction" << endl;
	cout << "\t 3. Delete a Transaction" << endl;
	cout << "\t 4. Go back to the Menu" << endl;
	cout << "\t ENTER THE NO. OF THE FUNCTION(1-4): \t";
	cin >> option;
	cout << endl << endl;
	switch (option) {
	case 1: addTransaction();
		break;
	case 2: editTransaction();
		break;
	case 3: deleteTransaction();
		break;
	case 4: system("CLS");
		return;
		break;
	default: cout << "\t THE VALUE YOU HAVE ENTERED IS INCORRECT.!!!!!!" << endl << endl;
	}
	transactionFunctionMenu();
}

void TransactionController::viewTransactionList(){}

void TransactionController::addTransaction(){
	//Clears console//
	system("CLS");

	int id;
	string transactionName;
	double amount;
	string note;
	string date;
	string time;

	int categoryNumber;
	bool categoryStatus = true;

	transactionName = ConsoleIO::in("\t \t \t ADD Transaction \nEnter the name of the Transaction:");

	amount = stod(ConsoleIO::in("Enter the amount of the Transaction: ", AMOUNT));

	note = ConsoleIO::in("Enter the note for the transaction");

	date = ConsoleIO::in("Enter the date for the transaction (dd/mm/yyyy): ");

	time = ConsoleIO::in("Enter the time of the transaction (hh:mm): ");

	do
	{

	} while (categoryStatus);
}

void TransactionController::editTransaction(){}

void TransactionController::deleteTransaction(){}
