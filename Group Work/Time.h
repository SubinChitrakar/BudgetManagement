#include<string>
#include <ctime> 
#include <iostream>

using namespace std;

class Time
{
private: 
	struct tm newtime;
	time_t now;
public:
	Time();
	int getMinute();
	int getHour();
	string getCurrentTime();

	string getDayofWeek();
	
	int getDay();
	int getMonth();
	int getYear();
	string getCurrentDate();

	string findDayOfWeek(int day, int month, int year);

	string getCurrentDateAndTime();
};

