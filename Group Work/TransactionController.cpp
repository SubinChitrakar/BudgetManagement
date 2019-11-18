#include "pch.h"
#include "TransactionController.h"
#include "NormalTransaction.h"
#include "ConsoleIO.h"

void TransactionController::transactionFunctionMenu(DataConverter* dc, vector<Category>& cat){
	int option = 0;

	viewNormalTransactionList();

	ConsoleIO::out("\n1.Add   2.Edit   3.Delete   4.Delete recurring   5.Go back\n");

	option = stoi(ConsoleIO::in("Please, choose menu item to continue:", NUMBER, 1));

	switch (option) {
	case 1: addTransaction(cat);
		break;
	case 2: if (normalTransactionList.size() > 0) editTransaction(cat);
		break;
	case 3: if (normalTransactionList.size() > 0) deleteNormalTransaction();
		break;
	case 4: if (recurringTransactionList.size() > 0) deleteRecurringTransaction();
		break;
	case 5: 
		return;
		break;
	}

	dc->convertFromNormalTransaction(normalTransactionList);
	dc->convertFromRecurringTransaction(recurringTransactionList);

	transactionFunctionMenu(dc, cat);
}

void TransactionController::addTransaction(vector<Category>& cat){

	string info = "ADD TRANSACTION\nPress ESC to cancel the operation.\n";

	NormalTransaction* ntr = new NormalTransaction();

	string val;
	bool status;

	string type;

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the name of the transaction:", TEXT, 100, false, false, true);
	if (val == " ") return;
	else ntr->setTransactionName(val);

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the amount of the transaction: ", AMOUNT, 8, false, false, true);
	if (val == " ") return;
	else ntr->setAmount(stod(val));

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the note for the transaction (press Enter to leave this space empty): ", TEXT, 100, true, false, true);
	if (val == " ") return;
	else ntr->setNote(val);

	status = true;
	do
	{
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Select the transaction type:\n1. Income\n2. Expense", NUMBER, 1, false, false, true);
		if (val == " ") return;
		else {
			int opt = stoi(val);
			if (opt == 1 || opt == 2) {
				type = (opt == 1) ? "Income" : "Expense";
				status = false;
			}
		}
	} while (status);

	vector<int> catShow;
	string catList;

	for (int i = 0; i < cat.size(); ++i)
	{

		if (cat.at(i).getType() == type) {
			catList += "\n" + to_string(catShow.size() + 1) + ". " + cat[i].getCategoryName();
			catShow.push_back(i);
		}
	}

	status = true;
	do {
		int size = to_string(catShow.size()).size();
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Choose the transaction category:" + catList, NUMBER, size, false, false, true);
		if (val == " ") return;
		else {
			int opt = stoi(val) - 1;
			if (opt >= 0 && opt < catShow.size()) {
				ntr->setCategory(&cat.at(catShow.at(opt)));
				status = false;
			}
		}
	} while (status);

	status = true;
	do {
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Enter the date for the transaction (DD/MM/YYYY): ", TEXT, 12, false, false, true);
		if (val == " ") return;
		else if (ConsoleIO::valDate(val)) { ntr->setDate(val); status = false; }
	} while (status);


	status = true;
	do {
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Enter the time of the transaction (HH:MM): ", TEXT, 7, false, false, true);
		if (val == " ") return;
		else if (ConsoleIO::valTime(val)) { ntr->setTime(val);  status = false; }
	} while (status);

	status = true;
	do
	{
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Do you want to make this transaction as recurring?\n1. Yes\n2. No", NUMBER, 1, false, false, true);
		if (val == " ") return;
		else {
			int opt = stoi(val);
			if (opt == 1) {
				string res = getRecurringTransactionInput(*ntr, info);
				if (res == " ") return;
				status = false;
			}
			else if (opt == 2) {
				status = false;
			}
		}
	} while (status);

	int id = (normalTransactionList.size() > 0) ? normalTransactionList.back().getId() + 1 : 1;

	normalTransactionList.push_back(*ntr);

}

string TransactionController::getRecurringTransactionInput(NormalTransaction& tr, string& info) {
	bool status = true;
	string val;

	RecurringTransaction* rtr = new RecurringTransaction();

	rtr->setTransactionName(tr.getTransactionName());
	rtr->setAmount(tr.getAmount());
	rtr->setCategory(tr.getCategory());
	rtr->setNote(tr.getNote());
	rtr->setDate(tr.getDate());
	rtr->setTime(tr.getTime());

	do {
		
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Please, select type of recurring transaction:\n1. Daily\n2. Monthly", NUMBER, 1, false, false, true);
		if (val == " ") return " ";

		int opt = stoi(val);

		if (opt == 1 || opt == 2) {
			rtr->setRepeat((opt == 1) ? DAILY : MONTHLY);
			status = false;
		}

	} while (status);

	int id = (recurringTransactionList.size() > 0) ? recurringTransactionList.back().getId() + 1 : 1;

	rtr->setId(id);

	recurringTransactionList.push_back(*rtr);
	
	return string();
}

void TransactionController::editTransaction(vector<Category>& cat){

	string info = "EDIT TRANSACTION";
	string info_2 = "\nPress ESC to cancel the operation.\n";

	string val;
	bool status = true;
	int option;

	string type;

	do {
		viewNormalTransactionList();
		ConsoleIO::out("\n" + info + info_2);
		int size = to_string(normalTransactionList.size()).size();
		string numIn = ConsoleIO::in("Please, enter the number of the transaction:", NUMBER, size, false, false, true);

		if (numIn == " ") return;

		option = stoi(numIn) - 1;

		if (option >= 0 && option < normalTransactionList.size()) status = false;

	} while (status);

	NormalTransaction& ntr = normalTransactionList.at(option);

	ConsoleIO::out(info + ": " + ntr.getTransactionName() + info_2, true);
	val = ConsoleIO::in("Enter the name of the transaction (press Enter to leave current name):", TEXT, 100, true, false, true);
	if (val == " ") return;
	else if (val.size() > 0) ntr.setTransactionName(val);

	ConsoleIO::out(info + ": " + ntr.getTransactionName() + info_2, true);
	val = ConsoleIO::in("Enter the amount of the transaction (press Enter to leave current amount):", AMOUNT, 8, true, false, true);
	if (val == " ") return;
	else if (val.size() > 0) ntr.setAmount(stod(val));

	ConsoleIO::out(info + ": " + ntr.getTransactionName() + info_2, true);
	val = ConsoleIO::in("Enter the note for the transaction (press Enter to leave current note): ", TEXT, 100, true, false, true);
	if (val == " ") return;
	else if (val.size() > 0) ntr.setNote(val);

	status = true;
	do
	{
		ConsoleIO::out(info + ": " + ntr.getTransactionName() + info_2, true);
		val = ConsoleIO::in("Select the transaction type (press Enter to leave current type):\n1. Income\n2. Expense", NUMBER, 1, true, false, true);
		if (val == " ") return;
		else if (val.size() == 0) {
			type = ntr.getCategory()->getType();
			status = false;
		}
		else {
			int opt = stoi(val);
			if (opt == 1 || opt == 2) {
				type = (opt == 1) ? "Income" : "Expense";
				status = false;
			}
		}
	} while (status);

	vector<int> catShow;
	string catList;

	for (int i = 0; i < cat.size(); ++i)
	{

		if (cat.at(i).getType() == type) {
			catList += "\n" + to_string(catShow.size() + 1) + ". " + cat[i].getCategoryName();
			catShow.push_back(i);
		}
	}

	status = true;
	do {
		int size = to_string(catShow.size()).size();
		ConsoleIO::out(info + ": " + ntr.getTransactionName() + info_2, true);
		if (type == ntr.getCategory()->getType()) val = ConsoleIO::in("Choose the transaction category (press Enter to leave current category):" + catList, NUMBER, size, true, false, true);
		else  val = ConsoleIO::in("Choose the transaction category:" + catList, NUMBER, size, false, false, true);
		if (val == " ") return;
		else if (val.size() > 0) {
			int opt = stoi(val) - 1;
			if (opt >= 0 && opt < catShow.size()) {
				ntr.setCategory(&cat.at(catShow.at(opt)));
				status = false;
			}
		}
	} while (status);

	ConsoleIO::out(info + ": " + ntr.getTransactionName() + info_2, true);
	val = ConsoleIO::in("Enter the date for the transaction (DD/MM/YYYY) (press Enter to leave current date): ", TEXT, 12, true, false, true);
	if (val == " ") return;
	else if (val.size() > 0) ntr.setDate(val);

	ConsoleIO::out(info + ": " + ntr.getTransactionName() + info_2, true);
	val = ConsoleIO::in("Enter the time of the transaction (HH:MM) (press Enter to leave current time): ", TEXT, 7, true, false, true);
	if (val == " ") return;
	else if (val.size() > 0) ntr.setTime(val);

	normalTransactionList.at(option) = ntr;
}

void TransactionController::viewRecurringTransactionList() {

	ConsoleTable table(samilton::Alignment::centre);

	table.setIndent(1, 1);

	table[0][0] = "#";
	table[0][1] = "Name";
	table[0][2] = "Amount (GBP)";
	table[0][3] = "Type";
	table[0][4] = "Category";
	table[0][5] = "Notes";
	table[0][6] = "Date & time";
	table[0][7] = "Repitition";

	ConsoleIO::out({}, true);

	if (recurringTransactionList.size() > 0) {
		int count = 1;
		for (RecurringTransaction& rtr : recurringTransactionList) {
			table[count][0] = to_string(count);
			table[count][1] = rtr.getTransactionName();
			table[count][2] = ConsoleIO::dbl(rtr.getAmount());
			table[count][3] = rtr.getCategory()->getType();
			table[count][4] = rtr.getCategory()->getCategoryName();
			table[count][5] = rtr.getNote();
			table[count][6] = rtr.getDate() + " " + rtr.getTime();
			table[count][7] = (rtr.getRepeat() == 0) ? "Daily" : "Monthly";
			count++;
		}
	}
	else {
		table[1][0] = "";
	}

	cout << table;
}

void TransactionController::viewNormalTransactionList() {

	ConsoleTable table(samilton::Alignment::centre);

	table.setIndent(1, 1);

	table[0][0] = "#";
	table[0][1] = "Name";
	table[0][2] = "Amount (GBP)";
	table[0][3] = "Type";
	table[0][4] = "Category";
	table[0][5] = "Notes";
	table[0][6] = "Date & time";

	ConsoleIO::out({}, true);

	if (normalTransactionList.size() > 0) {
		int count = 1;
		for (NormalTransaction& ntr : normalTransactionList) {
			table[count][0] = to_string(count);
			table[count][1] = ntr.getTransactionName();
			table[count][2] = ConsoleIO::dbl(ntr.getAmount());
			table[count][3] = ntr.getCategory()->getType();
			table[count][4] = ntr.getCategory()->getCategoryName();
			table[count][5] = ntr.getNote();
			table[count][6] = ntr.getDate() + " " + ntr.getTime();
			count++;
		}
	}
	else {
		table[1][0] = "";
	}

	cout << table;
}

void TransactionController::deleteNormalTransaction(){
	int option;
	bool status = true;
	string info = "DELETE TRANSACTION\nPress ESC to cancel the operation.\n";
	int size = to_string(normalTransactionList.size()).size();
	do {
		viewNormalTransactionList();
		ConsoleIO::out("\n" + info);
		string numIn = ConsoleIO::in("Please, enter the number of transaction:", NUMBER, size, false, false, true);
		if (numIn == " ") return;
		option = stoi(numIn) - 1;

		if (option >= 0 && option < normalTransactionList.size()) status = false;

	} while (status);

	status = true;
	do {
		viewNormalTransactionList();
		ConsoleIO::out("\n" + info);
		string val = ConsoleIO::in("Do you really want to delete \"[" + to_string(option + 1) + string("] ") + normalTransactionList.at(option).getTransactionName() + string("\" transaction?\n1. Yes\n2. No"), NUMBER, 1, false, false, true);
		if (val == " " || val == "2") return;
		else if (val == "1") {
			status = false;
			normalTransactionList.erase(normalTransactionList.begin() + option);
		}
	} while (status);
}

void TransactionController::deleteRecurringTransaction(){
	int option;
	bool status = true;
	string info = "DELETE RECURRING TRANSACTION\nPress ESC to cancel the operation.\n";
	int size = to_string(recurringTransactionList.size()).size();
	do {
		viewRecurringTransactionList();
		ConsoleIO::out("\n" + info);
		string numIn = ConsoleIO::in("Please, enter the number of transaction:", NUMBER, size, false, false, true);
		if (numIn == " ") return;
		option = stoi(numIn) - 1;

		if (option >= 0 && option < recurringTransactionList.size()) status = false;

	} while (status);

	status = true;
	do {
		viewRecurringTransactionList();
		ConsoleIO::out("\n" + info);
		string val = ConsoleIO::in("Do you really want to delete \"[" + to_string(option+1) + string("] ") + recurringTransactionList.at(option).getTransactionName() + string("\" transaction?\n1. Yes\n2. No"), NUMBER, 1, false, false, true);
		if (val == " " || val == "2") return;
		else if (val == "1") {
			recurringTransactionList.erase(recurringTransactionList.begin() + option);
			status = false;
		}
	} while (status);
}
