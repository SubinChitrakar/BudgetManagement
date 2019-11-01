#include "pch.h"
#include <string>
#include "DataReader.h"
#include "Budget.h"
#include "Authorization.h"
#include "EncryptDecrypt.h"

using namespace std;

EncryptDecrypt ed;

void doIt() {
	string data = ed.fileDecrypt();
	ed.fileEncrypt(data);
}

void getInput(string type) {

}

int main()
{
	new Authorization(ed);
	doIt();
	string x;
	cin >> x;
}