#include "pch.h"
#include <string>
#include <stdio.h>
#include "DataReader.h"
#include "DataConverter.h"
#include "CategoryController.h"
#include "Authorization.h"
#include "EncryptDecrypt.h"
#include "ConsoleIO.h"

using namespace std;

EncryptDecrypt ecd;

int main()
{
	Authorization* auth = new Authorization(ecd);
	string data = ecd.getData();
	ConsoleIO::out(data);
	/*DataReader da;
	json j = da.readData();
	DataConverter dc;
	CategoryController categoryController;
	categoryController.setCategoryList(dc.convertToClass(j));
	categoryController.categoryFunctionMenu();
	*/
}