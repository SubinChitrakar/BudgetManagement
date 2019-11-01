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
	string defaultData = "{\"user\":{\"username\":\"qwe\",\"password\":\"asd\",\"budget\":{\"now\":0,\"total\":0}},\"categories\":[{\"id\":1,\"name\":\"Transport\",\"type\":\"expense\",\"budget\":{\"now\":0,\"total\":0}},{\"id\":2,\"name\":\"Salary\",\"type\":\"income\",\"budget\":{\"now\":0,\"total\":0}}],\"transactions\":[{\"id\":1,\"name\":\"TFL rail\",\"amount\":1.23,\"status\":\"expense\",\"category\":1,\"note\":\"Travel to museum\"}]}";
public:
	json readData();
	void writeData(json& j);
	void generateData();
};

