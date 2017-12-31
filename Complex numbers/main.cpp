#include <iostream>
#include <istream>
#include <fstream>
#include <string>

#include "complex.h"

using namespace std;

int main() {


	std::string inputFile = "complex-1.txt";
	std::string outputFile = "complexObj.txt";

	std::ifstream is(inputFile);
	if (!is.is_open()) {
		std::cout << "Cannot open input file: " << inputFile << std::endl;
		return -1;
	}

	std::ofstream os(outputFile);
	if (!os.is_open()) {
		std::cout << "Cannot open output file: " << outputFile << std::endl;
		return -1;
	}

	Complex c, total(0, 0);
	std::string line;
	while (is >> c) {
		// std::cout << "main: got c [" << c << "]" << std::endl;
		if (c.valid()) {
			os << c << std::endl;
			total = total + c;
		}
	}

	os << total << std::endl;

	return 0;
}