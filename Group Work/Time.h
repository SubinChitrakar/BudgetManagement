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

	void addDay(int i) { newtime.tm_mday += i; };

	void convertToDate(string date);
	void convertToTime(string time);
};
