#include "pch.h"
#include "RecurringProcess.h"


void RecurringProcess::runProcess(DataConverter* dc, vector<RecurringTransaction>& rtr, vector<NormalTransaction>& ntr, vector<Category>& cat)
{
	User* user = dc->convertToUser();
	Time* time = new Time();
	user->setLastAccessDate(to_string(time->getDay()) + "/" + to_string(time->getMonth()) + "/" + to_string(time->getYear()));
	user->setLastAccessTime(to_string(time->getHour()) + ":" + to_string(time->getMinute()));
	dc->convertFromUser(*user);

	vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int rtrSize = rtr.size();
	//int count = getDifference();

	for (int i = 0; i < rtrSize; i++) {
		
	}

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
	if (difference == 2) return 28;
	else if (difference == 3) return 29;
	return 0;
}
