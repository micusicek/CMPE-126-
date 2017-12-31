#pragma once
#include <iostream>

#include "Stock.h"

class Node {
private:
	Stock s;
	Node *next;
	Node *prev;
public:
	Node();
	Node(const Node& n);
	Node(Stock s, Node *prev, Node *next);

	bool valid() { return this->s.valid(); }
	Stock& getS() { return this->s; }
	Node *getNext() { return this->next; }
	Node *getPrev() { return this->prev; }
	void setNext(Node *n) { this->next = n; }
	void setPrev(Node *n) { this->prev = n; }

	friend std::ostream& operator<< (std::ostream& os, const Node& n);
	friend std::istream &operator>> (std::istream& is, Node& n);

};
