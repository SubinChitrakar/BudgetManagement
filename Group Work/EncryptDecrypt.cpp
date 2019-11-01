#include "pch.h"
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

void EncryptDecrypt::fileEncrypt(string str) {
	int now, last;

	//str = readFile();

	for (int i = 0; str[i] != '\0'; i++) {
		now = int(str[i]);
		last = now + keySize;
		if (last > 127) last -= 127;
		str[i] = last;
	}

	writeFile(str);
}

string EncryptDecrypt::fileDecrypt() {
	int now, last;

	string data = readFile();

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
	ifstream t(filename);
	string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
	return str;
}