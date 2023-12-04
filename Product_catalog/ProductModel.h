#pragma once
class ProductModel
{
	int id;
	std::string name;
	std::string manufacturer;
	double price;
public:
	ProductModel();
	ProductModel(int id, std::string name, std::string manufacturer, double price);
	int getID();
	std::string getName();
	std::string getManufacturer();
	double getPrice();
	std::string setName(const std::string& name);
	std::string setManufacturer(const std::string& manufacturer);
	double setPrice(const double& price);
	void display();
};

