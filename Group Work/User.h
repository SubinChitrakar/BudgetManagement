#pragma once
#include <string>
#include "json.hpp"

using nlohmann::json;
using namespace std;

class User
{
private:
	string password;
	double limit;
	string lastAccess;
public:
	User(json& j);

	string getLastAccess(){ return lastAccess; }
	string getPassword() { return password; }
	double getLimit() { return limit; }

	void setLastAccess(string _lastAccess) { lastAccess = _lastAccess; }
	void setPassword(string _password) { password = _password; }
	void setLimit(double _limit) { limit = _limit; };
};

