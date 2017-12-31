#include <iostream>
#include <regex>

#include "Stock.h"

Stock::Stock() {
	symbol = "";
	price = 0;
	numberOfShares = 0;
	isValid = false;
}

Stock::Stock(std::string symbol, double price, int numberOfShares, bool isValid) {
	this->symbol = symbol;
	this->price = price;
	this->numberOfShares = numberOfShares;
	this->isValid = isValid;
}

std::ostream& operator<< (std::ostream& os, const Stock& s) {
	if (s.isValid) {
		os << s.symbol << ",$" << s.price << "," << s.numberOfShares;
	} else {
		os << "INVALID_STOCK";
	}
	return os;
}

std::istream &operator>> (std::istream& is, Stock& s) {
	std::string line;
	is >> line;
	std::string reString = "^([a-zA-Z0-9]+),[$]([0-9.]+),([0-9]+)$";
	std::regex re(reString);
	std::smatch m;
	if (std::regex_match(line, m, re)) {
		s.symbol         = m[1];
		s.price          = std::stod(m[2], NULL);
		s.numberOfShares = std::stoi(m[3], NULL);
		s.isValid        = true;
	} else {
		s.symbol         = "";
		s.price          = 0.0;
		s.numberOfShares = 0;
		s.isValid        = false;
	}

	return is;
}
