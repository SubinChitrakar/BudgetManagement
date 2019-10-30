#pragma once
#include <string>
#include "Budget.h"

using namespace std;

class User
{
private:
	string username;
	string password;
	Budget userBudget;
public:
	

	string getUsername(){ return username; }
	string getPassword() { return password; }
	Budget getUserBudget() { return userBudget; }

	void setUsername(string _userName) { username = _userName; }
	void setPassword(string _password) { password = _password; }
	void setUserBudget(Budget _userBudget) { userBudget = _userBudget; }
};

