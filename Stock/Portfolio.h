#pragma once

#include <iostream>

#include "Node.h"

class Portfolio {
private:
	Node *head;
	Node *tail;
public:
	Portfolio();
	~Portfolio();

	void load(std::string filename);
	void save(std::string filename);

	void insertFront(Node *n);
	void insertMiddle(std::string afterSymbol, Node *n);
	void insertBack(Node *n);

	void deleteAll();

	void print(std::ostream& os = std::cout);
	void printReverse(std::ostream& os = std::cout);
};