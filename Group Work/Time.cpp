#include "pch.h"
#include "Time.h"


Time::Time(){
	newtime;
	now = time(0);
	localtime_s(&newtime, &now);
}

int Time::getMinute() {
	int minutes = newtime.tm_min;
	return minutes;
}

int Time::getHour() {
	int hour = newtime.tm_hour;
	return hour;
}

int Time::getDay() {
	int day = newtime.tm_mday;
	return day;
}

int Time::getMonth() {
	int month = 1 + newtime.tm_mon;
	return month;
}

int Time::getYear() {
	int year = 1900 + newtime.tm_year;
	return year;
}

void Time::convertToDate(string date) {
	string delimiterForDate = "/";
	int pos = 0;
	pos = date.find(delimiterForDate);
	string day = date.substr(0, pos);
	date.erase(0, pos + delimiterForDate.length());

	pos = date.find(delimiterForDate);
	string month = date.substr(0, pos);
	date.erase(0, pos + delimiterForDate.length());

	string year = date;

	newtime.tm_mday = stoi(day);
	newtime.tm_mon = stoi(month) - 1;
	newtime.tm_year = stoi(year) - 1900;

}

void Time::convertToTime(string time) {
	string delimiterForDate = ":";
	
	int pos = 0;
	pos = time.find(delimiterForDate);
	string hours = time.substr(0, pos);
	time.erase(0, pos + delimiterForDate.length());

	string minutes = time;
	newtime.tm_hour = stoi(hours);
	newtime.tm_min = stoi(minutes);
}