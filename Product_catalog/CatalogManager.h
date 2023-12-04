#pragma once
#include "ProductModel.h"

class CatalogManager
{
	std::vector<ProductModel> product;
public:
	void loadData();
	void saveData();
	void addProduct();
	void delProduct();
	void updateProduct();
	void displayStatistik();
	void display();
};

