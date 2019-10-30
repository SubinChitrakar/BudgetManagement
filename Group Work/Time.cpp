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
	case 5: nameOfTheDay = "Thrusday";
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
	string currentTimeAndDate = getCurrentTime()+" "+getDayofWeek()+" "+getCurrentDate();
	return currentTimeAndDate;
}



