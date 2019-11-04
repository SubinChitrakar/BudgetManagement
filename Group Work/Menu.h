#include "json.hpp"
#include "CategoryController.h"
#include "DataConverter.h"
#include "EncryptDecrypt.h"

class Menu
{
private:
	DataConverter* dc;
	CategoryController categoryController;

public:
	Menu(DataConverter* dca) {dc = dca;}
	void startMenu();
};

