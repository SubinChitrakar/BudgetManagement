#include "pch.h"
#include "NormalTransaction.h"

NormalTransaction::NormalTransaction(int id, string name, double amount, Category* cat, string note, Time* time) : Transaction(id, name, amount, cat, note){
	time = time;
}