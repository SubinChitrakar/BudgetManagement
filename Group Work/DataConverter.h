#pragma once
#include <string>
#include <iostream>

#include "json.hpp"

#include "EncryptDecrypt.h"
#include "Category.h"
#include "User.h"
#include "Category.h"
#include "NormalTransaction.h"

using nlohmann::json;
using namespace std;

class DataConverter
{
private:
	json& j;
	EncryptDecrypt& ec;
	void saveData() { ec.fileEncrypt(j.dump(), j["user"]["password"]); }
public:
	DataConverter(json& json, EncryptDecrypt& ecd) : j(json),ec(ecd) {};
	vector<Category> convertToCategory();
	vector<NormalTransaction> convertToNormalTransaction(vector<Category>& catList);
	void convertFromCategory(vector<Category> categoryList);
	void convertFromNormalTransaction(vector<NormalTransaction>& normalTransactionList);
};

