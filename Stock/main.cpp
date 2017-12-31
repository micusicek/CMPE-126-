#include <iostream>

#include "Stock.h"
#include "Node.h"
#include "Portfolio.h"

int main() {

	Portfolio p;
	std::string inputFilename = "stockIn.txt";
	std::string outputFilename = "stockOut.txt";

	p.load(inputFilename);
	std::cout << "Portfolio (from " << inputFilename << "): " << std::endl;
	p.print();
	std::cout << std::endl;

	p.save(outputFilename);

	Node *newHead = new Node(Stock("AAA", 12.3, 4), nullptr, nullptr);
	p.insertFront(newHead);

	Node *middle = new Node(Stock("MID", 50.50, 257), nullptr, nullptr);
	std::cout << "Please enter stock symbol after which to insert a new one: ";
	std::string symbol;
	std::cin >> symbol;
	std::cout << std::endl;
	p.insertMiddle(symbol, middle);

	Node *newTail = new Node(Stock("ZZZ", 1000.99, 7), nullptr, nullptr);
	p.insertBack(newTail);

	std::cout << "Portfolio: " << std::endl;
	p.print();
	std::cout << std::endl;

	std::cout << "Portfolio (reverse order): " << std::endl;
	p.printReverse();
	std::cout << std::endl;

	return 0;
}