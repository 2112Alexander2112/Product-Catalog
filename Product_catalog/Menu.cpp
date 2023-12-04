#include "Header.h"
#include "Menu.h"

Menu::Menu(std::string appName, std::vector<std::string> menuItem)
	: appName(appName), menuItem(menuItem)
{
}

void Menu::displayAppMenu()
{
	system("cls");
	std::cout << "\n=======================================";
	std::cout << "\n> Program:  " << appName;
	std::cout << "\n=======================================" << std::endl;
}

void Menu::displayItem()
{
	for (int i = 0; i < menuItem.size(); i++) {
		std::cout << i + 1 << ".  ";
		std::cout << menuItem[i] << std::endl;
	}
}

int Menu::choiceProgram()
{
	int choice;
	std::cout << "\n> Make a choice: ";
	std::cin >> choice;
	return choice;
}

bool Menu::allowProgram()
{
	std::string allow;
	std::cout << "\n> Continue? (y/n): ";
	std::cin >> allow;
	return (allow == "y" || allow == "Y");
}
