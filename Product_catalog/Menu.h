#pragma once
class Menu
{
	std::string appName;
	std::vector<std::string> menuItem;
public:
	Menu(std::string appName, std::vector<std::string> menuItem);
	void displayAppMenu();
	void displayItem();
	int choiceProgram();
	bool allowProgram();
};

