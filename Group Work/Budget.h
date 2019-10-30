#pragma once
#include "json.hpp"

using nlohmann::json;

	class Budget
	{
	public:
		double total;
		double now;
		Budget() { };
		Budget(json& j);
		double getTotal() { return total; }
		double getNow() { return now; }
		void addTotal(double _total) { total += _total; }
		void addNow(double _now) { now += _now; }
		void removeTotal(double _total) { total -= _total; }
		void removeNow(double _now) { now -= _now; }
	};