#pragma once
#include <string>
#include <iostream>

#include "json.hpp"

#include "EncryptDecrypt.h"
#include "Category.h"
#include "User.h"
#include "Category.h"
#include "NormalTransaction.h"
#include "RecurringTransaction.h"

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
	User* convertToUser();
	vector<Category> convertToCategory();
	vector<NormalTransaction> convertToNormalTransaction(vector<Category>& catList);
	vector<RecurringTransaction> convertToRecurringTransaction(vector<Category>& catList);
	void convertFromCategory(vector<Category> categoryList);
	void convertFromNormalTransaction(vector<NormalTransaction>& normalTransactionList);
	void convertFromRecurringTransaction(vector<RecurringTransaction>& recurringTransactionList);
	void convertFromUser(User& user);
};

