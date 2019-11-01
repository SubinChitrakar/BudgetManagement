#pragma once
#include <string>
#include "json.hpp"
#include "category.h"

using nlohmann::json;

using namespace std;

class DataConverter
{
public:
	vector<Category> convertToClass(json& j);
};

