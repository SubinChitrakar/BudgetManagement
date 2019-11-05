#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


class EncryptDecrypt
{
private:
	string filename = "./data";
	int keySize;
	string decryptedData;
	string defaultData = "{\"user\":{\"last_access\":\"\",\"password\":\"%s\",\"limit\":200},\"categories\":[{\"id\":1,\"name\":\"Transport\",\"type\":\"Expense\",\"limit\":100},{\"id\":2,\"name\":\"Salary\",\"type\":\"Income\",\"limit\": 100}],\"transactions\":{\"normal\":[], \"recurring\":[]}}";
public:
	string& getData() { return decryptedData; };
	bool checkFile();
	string readFile();
	void writeFile(string data);
	void fileEncrypt(string data, string key);
	string fileDecrypt(string data);
	void setKeySize(string key);
	void generateData(string pw);
	string passwordToKey(string pw);
	bool checkPassword(string pw);
};

