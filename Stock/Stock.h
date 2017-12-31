#pragma once
#include <string>

class Stock
{
private:
	std::string symbol;
	double price;
	int numberOfShares;
	bool isValid;
public:
	Stock();
	Stock(std::string symbol, double price, int numberOfShares, bool isValid = true);

	std::string getSymbol() { return this->symbol; }
	bool valid() { return this->isValid; }

	friend std::ostream& operator<< (std::ostream& os, const Stock& s); // s is the object of the class Stock
	friend std::istream &operator>> (std::istream& is, Stock& s);
};
