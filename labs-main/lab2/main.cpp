#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "pair.hpp"
#include "list.hpp"

int main(int argc, char** argv) {
	l2::List<int,5> l2 {};

	bool keepreading;

	std::ofstream ofs("Lab2Output.txt");

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "\nInventory\n=========\n";
	l2::List <l2::Pair<std::string, double>, 5> inventory;

	std::string str;
	double price;

	keepreading = true;
	do {
		std::cout << "Product: ";
		getline(std::cin, str);
		if (str == "quit") {
			keepreading = false;
		}
		else {
			std::cout << "Price : ";
			std::cin >> price;
			std::cin.ignore();
			l2::Pair <std::string, double> pair(str, price);
			inventory += pair;
		}
	} while (keepreading);

	ofs << "\nPrice List\n-----------\n";
	for (size_t i = 0; i < inventory.size(); i++)
		ofs << inventory[i].getKey()
		<< " : " << inventory[i].getValue() << std::endl;

	std::cout << "\nGlossary\n========\n";
	l2::List <l2::Pair<std::string, std::string>, 5> glossary;
	std::string key, definition;

	keepreading = true;
	do {
		std::cout << "Key : ";
		getline(std::cin, key);
		if (key == "quit") {
			keepreading = false;
		}
		else {
			std::cout << "Definition : ";
			getline(std::cin, definition);
			l2::Pair <std::string, std::string> pair(key, definition);
			glossary += pair;
		}
	} while (keepreading);

	ofs << "\nEntries\n-------\n";
	for (size_t i = 0; i < glossary.size(); i++)
		ofs << glossary[i].getKey()
		<< " : " << glossary[i].getValue() << std::endl;

	ofs.close();
}