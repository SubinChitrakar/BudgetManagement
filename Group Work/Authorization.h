#pragma once
#include <iostream>
#include <string>
#include "ConsoleIO.h"
#include "EncryptDecrypt.h"

using namespace std;

class Authorization
{
private:
	int mistakes = 0;
	EncryptDecrypt& ed;
	string decryptedData;
public:
	void getPassword();
	Authorization(EncryptDecrypt& ecd);
};

