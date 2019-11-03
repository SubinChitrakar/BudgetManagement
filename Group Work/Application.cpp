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
	//ConsoleIO::out( ConsoleIO::in("Please, enter smth", TEXT, 3));
	new Authorization(ecd);
	/*DataReader da;
	json j = da.readData();
	DataConverter dc;
	CategoryController categoryController;
	categoryController.setCategoryList(dc.convertToClass(j));
	categoryController.categoryFunctionMenu();
	*/
}