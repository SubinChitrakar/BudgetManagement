#pragma once
#include <string>
#include <iostream>
#include <ctype.h>
#include <conio.h>
#include "InputTypes.h"
#include <vector>

using namespace std;

class ConsoleIO
{
private:
	static bool letter;
	static bool number; 
	static bool symbol; 
	static bool dot;
	static bool isDot;
	static void checkType(InputTypes &type);
public:
	static void out(string data = "", bool clear = false);
	static string in(string data, InputTypes type = TEXT, int size = 100, bool isEnter = false, bool isSecret = false, bool isEsc = false);
	static string dbl(double num);
	static bool valDate(string date);
	static bool valTime(string time);
};

