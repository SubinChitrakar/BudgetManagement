#include "pch.h"
#include "RecurringProcess.h"


void RecurringProcess::runProcess(DataConverter* dc, vector<RecurringTransaction>& rtr, vector<NormalTransaction>& ntr, vector<Category>& cat)
{
	User* user = dc->convertToUser();
	Time* time = new Time();
	user->setLastAccessDate(to_string(time->getDay()) + "/" + to_string(time->getMonth()) + "/" + to_string(time->getYear()));
	user->setLastAccessTime(to_string(time->getHour()) + ":" + to_string(time->getMinute()));
	dc->convertFromUser(*user);

	

	cout << "";
}
