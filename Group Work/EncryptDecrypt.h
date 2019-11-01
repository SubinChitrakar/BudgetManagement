#pragma once
#include<iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>

using namespace std;


class EncryptDecrypt
{
private:
	string filename = "./data";
	string key = "thisiskey";
	int keySize;
public:
	string readFile();
	void writeFile(string data);
	void fileEncrypt(string data);
	string fileDecrypt();
	void setKeySize(string key);
};

