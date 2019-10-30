#include "pch.h"
#include "User.h"

User::User(json& j) {
	username = j["username"].get<string>();
	password = j["password"].get<string>();
	json budget = j["budget"];
	userBudget = new Budget(budget);
}