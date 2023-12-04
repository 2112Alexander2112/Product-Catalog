#include "Header.h"
#include "CatalogManager.h"

void CatalogManager::loadData()
{
	std::ifstream fin;
	fin.clear();
	fin.open("Product.txt");
	while (!fin.eof()) {
		int id;
		std::string name;
		std::string manufacturer;
		double price;

		fin >> id;
		fin.ignore();
		std::getline(fin, name);
		std::getline(fin, manufacturer);
		fin >> price;
		fin.ignore();
		ProductModel model(id, name, manufacturer, price);
		product.push_back(model);
	};
	product.pop_back();
	fin.close();
}

void CatalogManager::saveData()
{
	std::ofstream fout;
	fout.open("Product.txt");
	for (int i = 0; i < product.size(); i++) {
		auto temp = product[i];
		fout << temp.getID() << std::endl;
		fout << temp.getName() << std::endl;
		fout << temp.getManufacturer() << std::endl;
		fout << temp.getPrice() << std::endl;
	}
	fout.close();

}

void CatalogManager::addProduct()
{
	int id;
	std::string name;
	std::string manufacturer;
	double price;

	id = product.back().getID() + 1;
	std::cout << "\n> Enter product name: ";
	std::cin >> name;
	std::cout << "\n> Enter manufacturer name: ";
	std::cin >> manufacturer;
	std::cout << "\n> Enter the price of the product: ";
	std::cin >> price;
	ProductModel model(id, name, manufacturer, price);
	product.push_back(model);
	saveData();
	
}

void CatalogManager::delProduct()
{
	int id;
	std::cout << "\n> Enter Product ID: ";
	std::cin >> id;
	auto iter = std::find_if(product.begin(), product.end(), [id](ProductModel& t) {
		return (t.getID() == id);
		});
	if (iter == product.end()) {
		std::cout << "\n> Product with this id was not found!!!" << std::endl;
	}
	else {
		product.erase(iter);
		saveData();
	}
}

void CatalogManager::updateProduct()
{

	int id;
	std::cout << "\n> Enter Product ID: ";
	std::cin >> id;
	auto iter = std::find_if(product.begin(), product.end(), [id](ProductModel& t) {
		return (t.getID() == id);
		});
	// -->
	if (iter == product.end()) {
		std::cout << "\n> Product with this id was not found!!!" << std::endl;
	}
	else {
		int choice;
		std::cout << "\n> 1. Change product name:" << std::endl;
		std::cout << "> 2. Change product manufacturer" << std::endl;
		std::cout << "> 3. Change product price:" << std::endl;
		std::cout << "\n> Make a choice what you want to change: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
		{
			std::string name;
			std::cout << "\n> Enter a new product name: ";
			std::cin >> name;
			iter->setName(name);
		}
			break;
		case 2:
		{
			std::string manufacturer;
			std::cout << "\n> Enter the name of the new manufacturer: ";
			std::cin >> manufacturer;
			iter->setManufacturer(manufacturer);
		}
			break;
		case 3:
		{
			double price;
			std::cout << "\n> Enter a new product name: ";
			std::cin >> price;
			iter->setPrice(price);
		}
			break;
		}
	}
	
	saveData();
}

void CatalogManager::displayStatistik()
{
	size_t count = product.size();
	double sum = std::accumulate(product.begin(), product.end(), 0.0, [](double sum, ProductModel& t) {
		return sum + t.getPrice();
		});

	std::cout << "\n> Number of goods: " << count << std::endl;
	std::cout << "> Average price of goods: " << sum / count << std::endl;
}

void CatalogManager::display()
{
	for (int i = 0; i < product.size(); i++) {
		product[i].display();
	}
}
