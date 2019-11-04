#include "json.hpp"
#include "CategoryController.h"
#include "DataConverter.h"

class Menu
{
private:
	DataConverter dc;
	CategoryController categoryController;
	json& j;

public:
	Menu(json& json) : j(json){}
	void startMenu();
};

