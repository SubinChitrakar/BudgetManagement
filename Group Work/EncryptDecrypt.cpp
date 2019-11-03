﻿#include "pch.h"
#include "EncryptDecrypt.h"

void EncryptDecrypt::setKeySize(string key) {
	int i;
	string size, keySizeString = "";
	for (i = 0; (i < 100 && key[i] != '\0'); i++) {
		keySizeString += to_string(int(key[i]));
	}
	for (i = 0; (i < 100 && keySizeString[i] != '\0'); i++) {
		if (keySizeString[i] != '1' && keySizeString[i] != '0') size += keySizeString[i];
	}
	istringstream(size) >> i;
	keySize = i % 127;
}

void EncryptDecrypt::fileEncrypt(string str, string key) {
	int now;

	//str = readFile();

	setKeySize(key);

	for (int i = 0; str[i] != '\0'; i++) {
		now = int(str[i]) + keySize;
		if (now > 127) now -= 127;
		str[i] = now;
	}

	key = passwordToKey(key);

	str.insert(0, key);

	writeFile(str);
}

string EncryptDecrypt::passwordToKey(string pw) {

	for (int i = 0; pw[i] != '\0'; i++) {
		int val, sum = 0;
		val = int(pw[i]);
		
		while (val != 0)
		{
			sum = sum + val % 10;
			val = val / 10;
		}
		
		val += sum;
		if (val > 127) val -= 127;
		pw[i] = val;
	}

	return pw;
}

string EncryptDecrypt::fileDecrypt() {
	int now, last;

	string data = readFile();

	if (data == "") return defaultData;

	for (int i = 0; data[i] != '\0'; i++) {
		now = int(data[i]);
		if (now < 75) now += 127;
		last = now - keySize;
		data[i] = last;
	}

	return data;
}

void EncryptDecrypt::writeFile(string data) {
	ofstream o(filename);
	o << data;
}

string EncryptDecrypt::readFile() {
	ifstream t(filename, fstream::in | fstream::out);
	if (!t) {
		return "";
	}
	string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
	return str;
}

void EncryptDecrypt::generateData(string pw) {
	fileEncrypt(defaultData, pw);
}

bool EncryptDecrypt::checkPassword(string pw) {

	string data = readFile();
	string key = passwordToKey(pw);
	string stored = "";

	for (int i = 0; pw[i] != '\0'; i++) {
		stored += data[i];
	}

	if (stored == key) return true;
	else return false;
}

bool EncryptDecrypt::checkFile() {
	ifstream t(filename, fstream::in | fstream::out);
	if (!t) return false; else return true;
}