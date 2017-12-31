#pragma once
#include <istream>
#include 

class Complex {
private:
	double r;
	double i;
	bool isValid;
public:
	Complex();
	Complex(double r, double i, bool isValid = true);
	~Complex();

	bool valid();

	//operator overload
	friend std::ostream& operator << (std::ostream& is, const Complex& c);
	friend std::istream& operator >> (std::istream& is, Complex& c);
	friend Complex operator + (const Complex& left, const Complex& right);
};



