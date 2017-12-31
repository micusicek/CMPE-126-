#include <iostream>

#include "autos.h"

int main()
{
	Autos as;

	// create inventory
	try {
		// add
		as.add("Ford", "Fiesta", "2017", "4123");
		as.add("Ford", "Mustang", "1965", "0034");
		as.add("Toyota", "Camry", "2003", "1234");
	}
	catch (const std::exception& e) {
		std::cout << "main: std::exception [" << e.what() << "]\n";
		exit(1);
	}

	bool done = false;
	int choice;

	// main menu
	while(!done) {
		std::cout << std::endl
			<< "1 - List all cars\n"
			<< "2 - Find a car\n"
			<< "3 - Sell a car\n"
			<< "4 - Add car to inventory\n"
			<< "5 - Quit\n\n"
			<< "Enter your choice and press return: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "\nAvailable cars:\n" << as << "\n";
			break;
		case 2:
		{
			std::string make, model, year, vin;
			std::cout << "Enter make  (or * for any): "; std::cin >> make;
			std::cout << "Enter model (or * for any): "; std::cin >> model;
			std::cout << "Enter year  (or * for any): "; std::cin >> year;
			std::cout << "Enter vin   (or * for any): "; std::cin >> vin;
			List<Auto> found;
			as.find(make, model, year, vin, found);
			std::cout << "Found these cars:\n" << found << "\n";
		}
			break;
		case 3:
		{
			std::string vin;
			std::cout << "Enter vin: "; std::cin >> vin;
			auto sold = as.sell(vin);
			std::cout << (sold ? "Car sold" : "Car sold (not available)" ) << "\n";
		}
			break;
		case 4:
		{
			std::string make, model, year, vin;
			std::cout << "Enter make  (or * for any): "; std::cin >> make;
			std::cout << "Enter model (or * for any): "; std::cin >> model;
			std::cout << "Enter year  (or * for any): "; std::cin >> year;
			std::cout << "Enter vin   (or * for any): "; std::cin >> vin;
			try {
				as.add(make, model, year, vin);
				std::cout << "Car added to inventory\n";
			}
			catch (const AutoExistsException& e) {
				std::cout << "Not added, car already in inventory\n";
			}
		}
		break;
		case 5:
			done = true;
			std::cout << "End of program, bye!\n";
			break;
		default:
			std::cout << "Invalid input, please choose again...\n";
			break;
		}
	}

	return 0;
}