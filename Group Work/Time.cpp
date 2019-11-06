#include "pch.h"
#include "Time.h"


Time::Time(){
	newtime;
	now = time(0);
	localtime_s(&newtime, &now);
}

string getNameOfTheDay(int dayOfTheWeek) {
	string nameOfTheDay;
	switch (dayOfTheWeek)
	{
	case 1: nameOfTheDay = "Sunday";
		break;
	case 2: nameOfTheDay = "Monday";
		break;
	case 3: nameOfTheDay = "Tuesday";
		break;
	case 4: nameOfTheDay = "Wednesday";
		break;
	case 5: nameOfTheDay = "Thursday";
		break;
	case 6: nameOfTheDay = "Friday";
		break;
	case 7: nameOfTheDay = "Saturday";
		break;
	}
	return nameOfTheDay;
}

int Time::getMinute() {
	int minutes = newtime.tm_min;
	return minutes;
}

int Time::getHour() {
	int hour = newtime.tm_hour;
	return hour;
}

string Time::getCurrentTime() {
	string currentTime = to_string(getHour()) + ":" + to_string(getMinute());
	return currentTime;
}

string Time::getDayofWeek() {
	int dayOfTheWeek = 1 + newtime.tm_wday;	
	return getNameOfTheDay(dayOfTheWeek);
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

string Time::getCurrentDate() {
	string currentDate = to_string(getDay()) + "/" + to_string(getMonth()) + "/" +to_string(getYear());
	return currentDate;
}

string Time::findDayOfWeek(int day, int month, int year) {
	static int t[] = { 0, 3, 2, 5, 0, 3,
					   5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	int dayOfTheWeek = 1+(year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
	return getNameOfTheDay(dayOfTheWeek);
}

string Time::getCurrentDateAndTime() {
	string currentTimeAndDate = getCurrentTime() + " " + getCurrentDate();
	return currentTimeAndDate;
}

/*
	Convert the Dates and saves it into newTime
*/
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

/*
	Converts the time and saves it into newTime
*/
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