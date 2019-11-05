#include "pch.h"
#include "ConsoleIO.h"


bool ConsoleIO::letter = false;
bool ConsoleIO::number = false;
bool ConsoleIO::symbol = false;
bool ConsoleIO::dot = false;
bool ConsoleIO::isDot = false;

void ConsoleIO::out(string data, bool clear) {
	if (clear) system("CLS");
	cout << data << endl << flush;
}

string ConsoleIO::in(string data, InputTypes type, int size, bool isEnter, bool isSecret, bool isEsc) {
	const char BACKSPACE = 8;
	const char RETURN = 13;
	const char ESC = 27;

	isDot = false;

	string input = "";
	unsigned char ch = 0;

	checkType(type);

	out(data);

	bool loop = true;

	while (loop)
	{
		ch = _getch();

		switch (ch)
		{
		case RETURN:
			if (isEnter) loop = false;
			else if (input.size() > 0) loop = false;
			else continue;
			break;
		case BACKSPACE:
			if (input.length() != 0)
			{
				cout << "\b \b";
				if (dot) {
					if (input[input.size() - 1] == '.') isDot = false;
				}
				input.resize(input.length() - 1);
			}
			break;
		case ESC:
			if (isEsc) return " ";
			break;
		case 0:
		case 224:
			continue;
			break;
		default:
			bool add = false;
			if (ch >= 48 && ch <= 57) if (number) add = true;
			if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) if (letter)  add = true; 
			if ((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126)) if (symbol) add = true;
			if (ch == 46 && dot) {
				if (input.size() > 0 && !isDot) {
					add = true;
					isDot = true;
				}
			}
			if ((input.size() > 0 && input.size() < (size - 1)) && ch == 32) add = true;

			if (add) {
				input += ch;
				if (isSecret) cout << '*';
				else cout << ch;
			}
			break;
		}
		if (input.size() == size) break;
	}
	out();
	return input;
}

string ConsoleIO::dbl(double num) {
	char a[10];
	sprintf_s(a, "%.2f", num);
	return string(a);
}

void ConsoleIO::checkType(InputTypes &type) {
	switch (type)
	{
	case TEXT:
		letter = true;
		number = true;
		symbol = true;
		dot = true;
		break;
	case AMOUNT:
		number = true;
		dot = true;
		symbol = false;
		letter = false;
		break;
	case NUMBER:
		number = true;
		symbol = false;
		letter = false;
		dot = false;
		break;
	case LET_NUM:
		letter = true;
		number = true;
		symbol = false;
		dot = false;
		break;
	default:
		break;
	}
}