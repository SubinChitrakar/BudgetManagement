#include "json.hpp"
#include "ConsoleIO.h"
#include "DataConverter.h"
#include "CategoryController.h"
#include "TransactionController.h"

class Menu
{
private:
	DataConverter* dc;
	CategoryController categoryController;
	TransactionController transactionController;

public:
	Menu(DataConverter* dca) {dc = dca;}
	void startMenu();
};

