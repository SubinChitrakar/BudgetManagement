#include "pch.h"
#include "ReportController.h"

void ReportController::reportFunctionMenu(DataConverter * dc, vector<Category>& cat, vector<NormalTransaction>& ntr)
{
	if (filter == NULL) filter = new Time();
	if (each == NULL) each = new Time();
	addMonth(0);
	addYear(0);
	
	showReport(dc, cat, ntr);

	string val = ConsoleIO::in("1.[<]Year  2.[<]Month  3.[>]Month  4.[>]Year  ESC.Go back\n", NUMBER, 1, false, false, true);
	if (val == " ") return;
	else {
		switch (stoi(val))
		{
		case 1:
			addYear(-1);
			break;
		case 2:
			addMonth(-1);
			break;
		case 3:
			addMonth(1);
			break;
		case 4:
			addYear(1);
			break;
		}
	}
	reportFunctionMenu(dc, cat, ntr);
}

void ReportController::addMonth(int plus) {
	if (plus == 0 && month == 0) month = filter->getMonth();
	month += plus;
	if (month > 12) month = month % 12;
	if (month == 0) month = 12;
}

void ReportController::addYear(int plus) {
	if (year == 0) if (year == 0) year = filter->getYear();
	year += plus;
}

void ReportController::showReport(DataConverter * dc, vector<Category>& cat, vector<NormalTransaction>& ntr) {
	filter->convertToDate("1/" + to_string(month) + "/" + to_string(year));
	vector<double> total;
	int catSize = cat.size();
	int ntrSize = ntr.size();
	for (int i = 0; i < catSize; i++) {
		total.push_back(0);
		for (int k = 0; k < ntrSize; k++) {
			each->convertToDate(ntr[k].getDate());
			if (filter->getYear() == each->getYear()) {
				if (filter->getMonth() == each->getMonth()) {
					if (ntr[k].getCategory()->getId() == cat[i].getId()) total.back() += ntr[k].getAmount();
				}
			}
		}
	}

	ConsoleTable table(samilton::Alignment::centre);
	table.setIndent(1, 1);

	table[0][0] = "Category";
	table[0][1] = "Budget limit";
	table[0][2] = "Current";
	table[0][3] = "Difference";

	for (int t = 0; t < catSize; t++) {
		int col = t + 1;

		double two = total[t];
		if (two != 0) if (cat[t].getType() == "Expense") two = -1 * total[t];

		double three = cat[t].getLimit() - total[t];
		//if (three < 0) three *= -1;
 
		table[col][0] = cat[t].getCategoryName();
		table[col][1] = ConsoleIO::dbl(cat[t].getLimit());
		table[col][2] = ConsoleIO::dbl(two);
		table[col][3] = ConsoleIO::dbl(three);
	}

	ConsoleIO::out("Report for " + to_string(filter->getMonth()) + "/" + to_string(filter->getYear()) + ":\n", true);
	cout << table << endl;
}