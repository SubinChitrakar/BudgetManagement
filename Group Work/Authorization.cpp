#include "pch.h"
#include "Authorization.h"


Authorization::Authorization(EncryptDecrypt& ecd) : ed(ecd)
{
	if (!ecd.checkFile()) {
		string pw = ConsoleIO::in("Please, enter new password:", TEXT, 100, false, true);
		ecd.generateData(pw);
	} else getPassword();
}

void Authorization::getPassword() {
	string pw;
	do {
		if (mistakes >= 3) exit(EXIT_FAILURE);
		string st = (mistakes == 0) ? "Please, enter your password:" : "Please, enter valid password:";
		pw = ConsoleIO::in(st, TEXT, 100, false, true);
		mistakes++;
	} while (!ed.checkPassword(pw));
}