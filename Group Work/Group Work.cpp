// Group Work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdio.h>
#include "DataReader.h"
#include "Budget.h"

typedef std::numeric_limits< double > dbl;

using namespace std;

Budget jsontoBudget(json& j) {
	Budget b;
	double d = j["income"];
	printf("%.2f\n", d);
	b.addIncome(j["income"]);
	b.addSpending(j["spending"]);
	return b;
}

int main()
{
	DataReader da;
	json j = da.readData();
	/*Budget b = jsontoBudget(j["budget"]);
	j["aaa"] = "asdasd";
	cout << b.getIncome() << endl;*/
	string x;
	cin >> x;
	da.writeData(j);
}