#include "pch.h"
#include "Budget.h"

	Budget::Budget(json& j) {
		total = j["total"].get<double>();
		now = j["now"].get<double>();
	}
