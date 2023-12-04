#include "Header.h"
#include "Menu.h"
#include "CatalogManager.h"

int main()

{
	std::string name = "Story";
	std::vector<std::string> item{
		{"Add Product"},
		{"Del Product"},
		{"Update Product"},
		{"Display statistics"},
		{"Display all products"},
		{"Finish Program"}
	};

	auto menu = std::make_unique<Menu>(name, item);
	auto product = std::make_unique<CatalogManager>();
	product->loadData();
	bool stop = false;
	do {
		menu->displayAppMenu();
		menu->displayItem();
		
		switch (menu->choiceProgram()) {
		case 1:
			product->addProduct();
			break;
		case 2:
			product->delProduct();
			break;
		case 3:
			product->updateProduct();
			break;
		case 4:
			product->displayStatistik();
			break;
		case 5:
			product->display();
			break;
		case 6:
			stop = true;
			break;
		}
		if (stop == true) {
			break;
		}

	} while (menu->allowProgram());
}


