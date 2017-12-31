#include "Node.h"

Node::Node() {
	this->s = Stock();
	this->next = nullptr;
	this->prev = nullptr;
}

Node::Node(const Node& n) {
	this->s = n.s;
	this->next = n.next;
	this->prev = n.prev;
}

Node::Node(Stock s, Node *prev, Node *next) {
	this->s = s;
	this->next = next;
	this->prev = prev;
}

std::ostream& operator<< (std::ostream& os, const Node& n) {
	os << n.s;
	return os;
}

std::istream &operator>> (std::istream& is, Node& n) {
	is >> n.s;
	return is;
}
