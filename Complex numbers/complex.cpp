#include "complex.h"
#include <istream>
#include <iostream>
#include <string>
#include <regex>

Complex::Complex() {
	this->r = 0.0;
	this->i = 0.0;
	this->isValid = true;
}

Complex::Complex(double r, double i, bool isValid) {
	this->r = r;
	this->i = i;
	this->isValid = isValid;
}

Complex::~Complex() {
}

bool Complex::valid() {
	return this->isValid;
}

std::ostream &operator << (std::ostream& os, const Complex& c) {
	if (c.isValid) {
		os << c.r << ((c.i >= 0) ? "+" : "") << c.i << 'i';
	} else {
		os << "<invalid complex number>";
	}

	return os;
}

std::istream &operator >> (std::istream& is, Complex& c) {
	std::string line;
	std::getline(is, line);
	std::string reString = "^(-{0,1}[0-9.]+)([-+][0-9.]+)(i)$";
	std::regex re(reString);
	std::smatch m;
	if (std::regex_match(line, m, re)) {
		c.r = std::stod(m[1], NULL);
		c.i = std::stod(m[2], NULL);
		c.isValid = true;
	} else {
		c.r = c.i = 0;
		c.isValid = false;
	}

	return is;
}

Complex operator + (const Complex& left, const Complex& right) {
	if (left.isValid && right.isValid) {
		return Complex(left.r + right.r, left.i + right.i);
	} else {
		return Complex(0, 0, false);
	}
}

// eof