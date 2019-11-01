// Group Work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
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