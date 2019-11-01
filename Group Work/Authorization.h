#pragma once
#include <iostream>
#include <string>
#include "EncryptDecrypt.h"

using namespace std;

class Authorization
{
private:
	int mistakes = 3;
	EncryptDecrypt& ed;
	string decryptedData;
public:
	void getPassword();
	bool checkPassword(string pw);
	Authorization(EncryptDecrypt& ecd);
};

