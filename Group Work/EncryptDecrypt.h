#pragma once
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
	string defaultData = "{\"user\":{\"username\":\"\",\"password\":\"\",\"budget\":{\"now\":0,\"total\":0}},\"categories\":[{\"id\":1,\"name\":\"Transport\",\"type\":\"expense\",\"budget\":{\"now\":0,\"total\":0}},{\"id\":2,\"name\":\"Salary\",\"type\":\"income\",\"budget\":{\"now\":0,\"total\":0}}],\"transactions\":[]}";
public:
	bool checkFile();
	string readFile();
	void writeFile(string data);
	void fileEncrypt(string data, string key);
	string fileDecrypt();
	void setKeySize(string key);
	void generateData(string pw);
	string passwordToKey(string pw);
	bool checkPassword(string pw);
};

