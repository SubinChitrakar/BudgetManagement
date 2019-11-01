#include "pch.h"
#include "User.h"

User::User(json& j) {
	username = j["username"].get<string>();
	password = j["password"].get<string>();
	userBudget = new Budget(j["budget"]);
}