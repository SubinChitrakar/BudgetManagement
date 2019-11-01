#include "pch.h"
#include "DataReader.h"

#include <iostream>
#include <string>

json DataReader::readData() {
	fstream ifs(filename, fstream::in | fstream ::out);

	if (!ifs) {
		generateData();
	}

	ifstream i(filename);
	json j;
	try
	{
		i >> j;

	}
	catch (const std::exception&)
	{
		generateData();
		ifstream i(filename);
		i >> j;
	}

	return j;
}

void DataReader::writeData(json& j) {
	ofstream o(filename);
	o << setw(4) << j << std::endl;
}

void DataReader::generateData() {
	ofstream o(filename);
	o << setw(4) << defaultData;
}