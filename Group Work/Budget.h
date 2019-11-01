#pragma once
#include "json.hpp"

using nlohmann::json;

	class Budget
	{
	private: 
		double total;
		double now;
	public:
		Budget() { };
		Budget(json& j);
		double getTotal() { return total; }
		double getNow() { return now; }
		void setTotal(double _total) { total = _total; }

		void addNow(double _now) { now += _now; }
		void removeNow(double _now) { now -= _now; }
	};