#include "pch.h"
#include "RecurringProcess.h"


void RecurringProcess::runProcess(DataConverter* dc, vector<RecurringTransaction>* rtr, vector<NormalTransaction>* ntr, vector<Category>* cat)
{
	if (rtr->size() <= 0) return;
	User* user = dc->convertToUser();

	vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int rtrSize = rtr->size();
	Time* last = new Time();
	if (user->getLastAccessDate() == "") user->setLastAccessDate(to_string(last->getDay()) + "/" + to_string(last->getMonth()) + "/" + to_string(last->getYear()));
	if (user->getLastAccessTime() == "") user->setLastAccessTime(to_string(last->getHour()) + ":" + to_string(last->getMinute()));
	last->convertToDate(user->getLastAccessDate());
	last->convertToTime(user->getLastAccessTime());
	Time* now = new Time();
	int count = getDifference(last->getDay(), last->getMonth(), last->getYear(), now->getDay(), now->getMonth(), now->getYear());

	for (int k = 0; k < count; k++) {
		string date = to_string(last->getDay()) + "/" + to_string(last->getMonth()) + "/" + to_string(last->getYear());
		for (int i = 0; i < rtrSize; i++) {
			bool cont = false;
			if (rtr->at(i).getDate() == date || rtr->at(i).getRepeat() == DAILY) cont = true;
			if (cont) {
				if (k == 0) {
					Time* temp = new Time();
					temp->convertToTime(rtr->at(k).getTime());
					if (temp->getHour() < last->getHour()) continue;
					else if (temp->getHour() == last->getHour() && temp->getMinute() < last->getMinute()) continue;
				}
				if (k == count - 1) {
					Time* temp = new Time();
					Time* temp_now = new Time();
					temp->convertToTime(rtr->at(k).getTime());
					if (temp->getHour() > temp_now->getHour()) continue;
					else if (temp->getHour() == temp_now->getHour() && temp->getMinute() > temp_now->getMinute()) continue;
				}
				int id = (ntr->size() > 0) ? ntr->back().getId() + 1 : 1;
				NormalTransaction* nt = new NormalTransaction();
				nt->setId(id);
				nt->setTransactionName(rtr->at(k).getTransactionName());
				nt->setAmount(rtr->at(k).getAmount());
				nt->setCategory(rtr->at(k).getCategory());
				nt->setNote(rtr->at(k).getNote());
				nt->setDate(rtr->at(k).getDate());
				nt->setTime(rtr->at(k).getTime());
				ntr->push_back(*nt);
			}
		}
		last->setDay(last->getDay() + 1);
		days.at(1) = getCount(last->getYear());
		if (last->getDay() > days.at(last->getMonth() - 1)) { last->setDay(1); last->setMonth(last->getMonth() + 1); }
		if (last->getMonth() > 12) { last->setMonth(1); last->setYear(last->getYear() + 1); }
	}

	dc->convertFromNormalTransaction(*ntr);

	Time* time = new Time();
	user->setLastAccessDate(to_string(time->getDay()) + "/" + to_string(time->getMonth()) + "/" + to_string(time->getYear()));
	user->setLastAccessTime(to_string(time->getHour()) + ":" + to_string(time->getMinute()));
	dc->convertFromUser(*user);

	cout << "";
}

int RecurringProcess::getDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
	struct tm a = { 0,0,0, d1, (m1 - 1), (y1 - 1900) };
	struct tm b = { 0,0,0,(d2 + 1), (m2 - 1), (y2 - 1900) };
	time_t x = mktime(&a);
	time_t y = mktime(&b);
	double difference = 0;
	if (x != (time_t)(-1) && y != (time_t)(-1))
	{
		difference = difftime(y, x) / (60 * 60 * 24);
	}
	return difference;
}

int RecurringProcess::getCount(int year) {
	struct tm a = { 0,0,0,28,1, (year - 1900) };
	struct tm b = { 0,0,0,1,2, (year - 1900) };
	time_t x = mktime(&a);
	time_t y = mktime(&b);
	double difference = 0;
	if (x != (time_t)(-1) && y != (time_t)(-1))
	{
		difference = difftime(y, x) / (60 * 60 * 24);
	}
	if (difference == 1) return 28;
	else if (difference == 2) return 29;
	return 0;
}
