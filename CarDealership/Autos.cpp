#include <iostream>

#include "Autos.h"

Autos::Autos() {}

Autos::~Autos() {}

void Autos::add(std::string make, std::string model, std::string year, std::string vin)
{
	if(vin2auto.get(vin, Auto())) {
		throw AutoExistsException();
	}
	vin2auto.put(vin, Auto(make, model, year, vin));
}

void Autos::find(std::string make, std::string model, std::string year, std::string vin, List<Auto> &found)
{
	for (auto i = 0; i < HASH_TABLE_SIZE; i++) {
		for (auto node = vin2auto.table[i]; node != nullptr; node = node->getNext()) {
			auto a = node->getValue();
			if (
				(make == "*") || (make == a.getMake()) &&
				(model == "*") || (model == a.getModel()) &&
				(year == "*") || (year == a.getYear()) &&
				(vin == "*") || (vin == a.getVin())
				)
			{
				found.insert(node->getValue());
			}
		}
	}
}

bool Autos::sell(std::string vin)
{
	return vin2auto.remove(vin);
}

std::ostream& operator<< (std::ostream& os, const Autos& as)
{
	std::cout << "[" << as.vin2auto << "]";
	return os;
}