#pragma once
#include <string>
#include "json.hpp"

using nlohmann::json;

using namespace std;

class DataConverter
{
public:
	vector<Category> convertToClass(json& j);
};

