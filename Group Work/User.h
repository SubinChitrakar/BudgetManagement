#pragma once
#include <string>
#include "json.hpp"

using nlohmann::json;
using namespace std;

class User
{
private:
	string password;
	string lastAccessDate;
	string lastAccessTime;
public:
	User(json& j);
	json getUser();

	string getLastAccessDate(){ return lastAccessDate; }
	string getLastAccessTime(){ return lastAccessTime; }
	string getPassword() { return password; }

	void setLastAccessDate(string _lastAccess) { lastAccessDate = _lastAccess; }
	void setLastAccessTime(string _lastAccess) { lastAccessTime = _lastAccess; }
	void setPassword(string _password) { password = _password; }
};

