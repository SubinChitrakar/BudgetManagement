// Group Work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdio.h>
#include "DataReader.h"
#include "Budget.h"
#include "User.h"
#include "DataConverter.h"

typedef std::numeric_limits< double > dbl;

using namespace std;

int main()
{
	DataReader da;
	json j = da.readData();
	DataConverter dc;
	vector<category> categoryList = dc.convertToClass(j);
	auto a = new User(j["user"]);
	/*Budget b = jsontoBudget(j["budget"]);
	j["aaa"] = "asdasd";
	cout << b.getIncome() << endl;*/
	string x;
	cin >> x;
	da.writeData(j);
}