#include "pch.h"
#include <string>
#include <stdio.h>

#include "Menu.h"
#include "Authorization.h"
#include "EncryptDecrypt.h"
#include "ConsoleIO.h"
#include "json.hpp"


using nlohmann::json;

using namespace std;

EncryptDecrypt ecd;

int main()
{
	Authorization* auth = new Authorization(ecd);

	string data = ecd.getData();
	ConsoleIO::out(data);
	json j = json::parse(data);

	Menu* menu = new Menu(j);
	menu->startMenu();

	

}