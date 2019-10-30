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
	string defaultData = "{\"user\":{\"username\":\"qwe\",\"password\":\"asd\",\"budget\":{\"now\":0,\"total\":0}},\"categories\":[{\"name\":\"Transport\",\"type\":\"expense\",\"budget\":{\"now\":0,\"total\":0}},{\"name\":\"Salary\",\"type\":\"income\",\"budget\":{\"now\":0,\"total\":0}}]}";
public:
	json readData();
	void writeData(json& j);
	void generateData();
};

