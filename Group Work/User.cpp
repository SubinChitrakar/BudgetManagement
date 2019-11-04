#include "pch.h"
#include "User.h"

User::User(json& j) {
	lastAccess = j["last_access"].get<string>();
	password = j["password"].get<string>();
	limit = j["limit"].get<double>();
}