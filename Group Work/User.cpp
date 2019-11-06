#include "pch.h"
#include "User.h"

User::User(json& j) {
	lastAccessDate = j["last_access_date"].get<string>();
	lastAccessTime = j["last_access_time"].get<string>();
	password = j["password"].get<string>();
}

json User::getUser() {
	json j;
	j["last_access_date"] = lastAccessDate;
	j["last_access_time"] = lastAccessTime;
	j["password"] = password;
	return j;
}