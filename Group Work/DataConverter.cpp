#include "pch.h"
#include "DataConverter.h"

using namespace std;

vector<Category> DataConverter::convertToCategory() {
	vector<Category> cat = {};
	for (json::iterator it = j["categories"].begin(); it != j["categories"].end(); ++it) {
		cat.push_back(Category(*it));
	}
	return cat;
}

vector<NormalTransaction> DataConverter::convertToNormalTransaction(vector<Category>& catList) {
	vector<NormalTransaction> tr = {};
	for (json::iterator it = j["transactions"]["normal"].begin(); it != j["transactions"]["normal"].end(); ++it) {
		Category* c = new Category();
		for (vector<Category>::iterator i = catList.begin(); i != catList.end(); ++i) {
			int index = distance(catList.begin(), i);
			if ((*i).getId() == (*it)["category"]) {
				c = &catList[index];
				break;
			}
		}
		tr.push_back(NormalTransaction(*it, *c));
	}
	return tr;
}

vector<RecurringTransaction> DataConverter::convertToRecurringTransaction(vector<Category>& catList) {
	vector<RecurringTransaction> tr = {};
	for (json::iterator it = j["transactions"]["recurring"].begin(); it != j["transactions"]["recurring"].end(); ++it) {
		Category* c = new Category();
		for (vector<Category>::iterator i = catList.begin(); i != catList.end(); ++i) {
			int index = distance(catList.begin(), i);
			if ((*i).getId() == (*it)["category"]) {
				c = &catList[index];
				break;
			}
		}
		tr.push_back(RecurringTransaction(*it, *c));
	}
	return tr;
}

void DataConverter::convertFromCategory(vector<Category> categoryList) {
	j["categories"].clear();
	for (auto i = categoryList.begin(); i != categoryList.end(); ++i) {
		j["categories"].push_back((*i).getCategory());
	}
	saveData();
}

void DataConverter::convertFromNormalTransaction(vector<NormalTransaction>& normalTransactionList) {
	j["transactions"]["normal"].clear();
	for (auto i = normalTransactionList.begin(); i != normalTransactionList.end(); ++i) {
		j["transactions"]["normal"].push_back((*i).getNormalTransaction());
	}
	saveData();
}

void DataConverter::convertFromRecurringTransaction(vector<RecurringTransaction>& recurringTransactionList) {
	j["transactions"]["recurring"].clear();
	for (auto i = recurringTransactionList.begin(); i != recurringTransactionList.end(); ++i) {
		j["transactions"]["recurring"].push_back((*i).getRecurringTransaction());
	}
	saveData();
}