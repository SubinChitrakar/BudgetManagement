#pragma once
#include <fstream>
#include <string>
#include "json.hpp"
#include <iomanip>

using nlohmann::json;

using namespace std;

class DataReader
{
private:
	string filename = ".\\data";
	string defaultData = "{\"user\":{\"budget\":{\"income\":0,\"spending\":0}},\"categories\":[{\"name\":\"Transport\",\"status\":\"expense\",\"budget\":{\"income\":0,\"spending\":0}},{\"name\":\"Salary\",\"status\":\"income\",\"budget\":{\"income\":0,\"spending\":0}}]}";
public:
	json readData();
	void writeData(json& j);
	void generateData();
};

