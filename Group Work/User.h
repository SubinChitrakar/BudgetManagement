#pragma once
#include <string>
#include "json.hpp"

using nlohmann::json;
using namespace std;

class User
{
private:
	string password;
	string lastAccess;
public:
	User(json& j);

	string getLastAccess(){ return lastAccess; }
	string getPassword() { return password; }

	void setLastAccess(string _lastAccess) { lastAccess = _lastAccess; }
	void setPassword(string _password) { password = _password; }
};

