#include "pch.h"
#include "TransactionController.h"
#include "NormalTransaction.h"
#include "ConsoleIO.h"

void TransactionController::transactionFunctionMenu(DataConverter* dc, vector<Category>& cat){
	int option = 0;

	ConsoleIO::out("TRANSACTIONS MENU\n1.Add transaction\n2.Edit transaction\n3.Delete transaction\n4.Go back\n", true);

	option = stoi(ConsoleIO::in("Please, choose menu item to continue:", NUMBER, 1));

	switch (option) {
	case 1: addTransaction(cat);
		break;
	case 2: editTransaction();
		break;
	case 3: deleteTransaction();
		break;
	case 4: 
		return;
		break;
	}

	dc->convertFromNormalTransaction(normalTransactionList);

	transactionFunctionMenu(dc, cat);
}

void TransactionController::addTransaction(vector<Category>& cat){

	string info = "ADD TRANSACTION\nPress ESC to cancel the operation.\n";

	NormalTransaction* ntr = new NormalTransaction();

	string val;
	bool status;

	string name;
	double amount;
	string note;
	string date;
	string time;
	string type;

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the name of the transaction:", TEXT, 100, false, false, true);
	if (val == " ") return;
	else name = val;

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the amount of the transaction: ", AMOUNT, 8, false, false, true);
	if (val == " ") return;
	else amount = stod(val);

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the note for the transaction (press Enter to leave this space empty): ", TEXT, 100, true, false, true);
	if (val == " ") return;
	else note = val;

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
			catList += "\n" + cat[i].getCategoryName();
			catShow.push_back(i);
		}
	}

	status = true;
	do {
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Choose the transaction category:" + catList, NUMBER, 3, false, false, true);
		if (val == " ") return;
		else {
			int opt = stoi(val) - 1;
			if (opt >= 0 && opt < catShow.size()) {
				//tr->setCategory(&catShow[opt]);

				ntr->setCategory(&cat.at(opt));
				status = false;
			}
		}
	} while (status);

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the date for the transaction (DD/MM/YYYY): ", TEXT, 12, false, false, true);
	if (val == " ") return;
	else date = val;

	ConsoleIO::out(info, true);
	val = ConsoleIO::in("Enter the time of the transaction (HH:MM): ", TEXT, 7, false, false, true);
	if (val == " ") return;
	else time = val;

	status = true;
	do
	{
		ConsoleIO::out(info, true);
		val = ConsoleIO::in("Do you want to make this transaction as recurring?\n1. Yes\n2. No", NUMBER, 1, false, false, true);
		if (val == " ") return;
		else {
			int opt = stoi(val);
			if (opt == 1) {
				//getNormalTransactionInput(*tr, info);
				status = false;
			}
			else if (opt == 2) {
				status = false;
			}
		}
	} while (status);

	int id = (normalTransactionList.size() > 0) ? normalTransactionList.back().getId() + 1 : 1;

	ntr->setTransactionName(name);
	ntr->setAmount(amount);
	ntr->setNote(note);
	ntr->setDate(date);
	ntr->setTime(time);
//	NormalTransaction(id, name, amount, *category, note, date, time)

	normalTransactionList.push_back(*ntr);

}

void TransactionController::getNormalTransactionInput(Transaction& tr, string& info) {
	
}

void TransactionController::editTransaction(){}

void TransactionController::viewTransactionList() {
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
	int count = 1;

	for (NormalTransaction& ntr : normalTransactionList) {
		table[count][0] = to_string(count);
		table[count][1] = ntr.getTransactionName();
		table[count][2] = ConsoleIO::dbl(ntr.getAmount());
		table[count][3] = ntr.getCategory()->getType();
		table[count][4] = ntr.getCategory()->getCategoryName();
		table[count][5] = ntr.getNote();
		table[count][6] = ntr.getDate() + " " + ntr.getTime();
	}
	cout << table;
}

void TransactionController::deleteTransaction(){
	viewTransactionList();
	string d;
	cin >> d;
}
