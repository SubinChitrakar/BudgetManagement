#include "pch.h"
#include <string>
#include <stdio.h>

#include "Menu.h"
#include "Authorization.h"
#include "EncryptDecrypt.h"
#include "ConsoleIO.h"
#include "DataConverter.h"
#include "json.hpp"


using nlohmann::json;

using namespace std;

EncryptDecrypt ecd;

int main()
{
	Authorization* auth = new Authorization(ecd);
	string data = ecd.getData();
	json j = json::parse(data);

	DataConverter* dc = new DataConverter(j, ecd);

	Menu* menu = new Menu(dc);
	menu->startMenu();

	

}