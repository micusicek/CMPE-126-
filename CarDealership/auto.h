#pragma once
#include <string>

class Auto
{
private:
	std::string make;
	std::string model;
	std::string year;
	std::string vin;
public:
	Auto() :make(), model(), year(), vin() {}
	Auto(std::string make, std::string model, std::string year, std::string vin) :make(make), model(model), year(year), vin(vin) {}
	std::string getMake() { return make; }
	std::string getModel() { return model; }
	std::string getYear() { return year; }
	std::string getVin() { return vin; }
	friend std::ostream& operator<< (std::ostream& os, const Auto& a)
	{
		os << "[" << a.make << ", " << a.model << ", " << a.year << ", " << a.vin << "]";
		return os;
	}
};

