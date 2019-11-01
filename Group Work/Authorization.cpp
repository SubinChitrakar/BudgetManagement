#include "pch.h"
#include "Authorization.h"


Authorization::Authorization(EncryptDecrypt& ecd) : ed(ecd)
{
	getPassword();
	cout << "shit" << endl;
}

void Authorization::getPassword() {
	string pw;
	do {
		if (mistakes == 0) exit(EXIT_FAILURE);
		string st = (mistakes == 3) ? "Please, enter your password." : "Please, enter valid password.";
		cout << st << endl;
		cin >> pw;
	} while (!checkPassword(pw));
}

bool Authorization::checkPassword(string pw) {
	ed.setKeySize(pw);
	string data = ed.fileDecrypt();
	if (data[0] != '{') {
		mistakes--;
		return false;
	};
	decryptedData = data;
	return true;
}
