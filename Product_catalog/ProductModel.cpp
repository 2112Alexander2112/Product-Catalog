#include "Header.h"
#include "ProductModel.h"

ProductModel::ProductModel()
	: id(0), name("---"), manufacturer("---"), price(0.0)
{
}

ProductModel::ProductModel(int id, std::string name, std::string manufacturer, double price)
	: id(id), name(name), manufacturer(manufacturer), price(price)
{
}

int ProductModel::getID()
{
	return id;
}

std::string ProductModel::getName()
{
	return name;
}

std::string ProductModel::getManufacturer()
{
	return manufacturer;
}

double ProductModel::getPrice()
{
	return price;
}

std::string ProductModel::setName(const std::string& name)
{
	return this->name = name;
}

std::string ProductModel::setManufacturer(const std::string& manufacturer)
{
	return this->manufacturer = manufacturer;
}

double ProductModel::setPrice(const double& price)
{
	return this->price = price;
}

void ProductModel::display()
{
	std::cout << std::setw(5) << id;
	std::cout << std::setw(20) << name;
	std::cout << std::setw(20) << manufacturer;
	std::cout << std::setw(12) << price << std::endl;
}
