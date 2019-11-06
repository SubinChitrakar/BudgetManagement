#pragma once
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
	int getDay();
	int getMonth();
	int getYear();

	void setDay(int i) { newtime.tm_mday = i; };
	void setMonth(int i) { newtime.tm_mon = i - 1; };
	void setYear(int i) { newtime.tm_year = i - 1900; };

	void convertToDate(string date);
	void convertToTime(string time);
};
