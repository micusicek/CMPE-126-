#pragma once

#include <string>

#include "hashTable.h"
#include "list.h"
#include "auto.h"

class AutoExistsException: public std::exception
{
private:
	std::string msg;
public:
	AutoExistsException(const std::string m = "Auto already exists") :msg(m) {}
	const char* what() const { return msg.c_str(); }
};

class Autos
{
private:
	HashTable<Auto> vin2auto;
public:
	Autos();
	~Autos();
	void add(std::string make, std::string model, std::string year, std::string vin);
	void find(std::string make, std::string model, std::string year, std::string vin, List<Auto> &found);
	bool sell(std::string vin);

	friend std::ostream& operator<< (std::ostream& os, const Autos& as);
};
