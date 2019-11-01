#include "pch.h"
#include <string>
#include <stdio.h>
#include "DataReader.h"
#include "DataConverter.h"
#include "CategoryController.h"

typedef std::numeric_limits< double > dbl;
using namespace std;


int main()
{
	DataReader da;
	json j = da.readData();
	DataConverter dc;
	CategoryController categoryController;
	categoryController.setCategoryList(dc.convertToClass(j));
	categoryController.categoryFunctionMenu();

}