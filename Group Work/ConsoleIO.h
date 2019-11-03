#pragma once
#include <string>
#include <iostream>
#include <ctype.h>
#include <conio.h>
#include "InputTypes.h"

using namespace std;

class ConsoleIO
{
private:
	static bool letter;
	static bool number; 
	static bool symbol; 
	static bool dot;
	static void checkType(InputTypes &type);
public:
	static void out(string data = "", bool newLine = true);
	static string in(string data, InputTypes type = TEXT, int size = 100, bool isEnter = false, bool isSecret = false);
};

