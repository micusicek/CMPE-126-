#pragma once
#include <cstddef>

template <typename Value>
class Node {
private:
	std::string key;
	Value value;
	Node *next; // next node in same bucket
	// no copy, assignment 
	Node(const Node &n);
	Node & operator=(const Node &n);
public:
	Node(const std::string &key, const Value &value) : key(key), value(value), next(NULL) {}
	std::string getKey() const { return key; }
	Value getValue() const { return value; }
	void setValue(Value value) { this->value = value; }
	Node *getNext() { return next; }
	void setNext(Node *next) { this->next = next; }

	friend std::ostream& operator<< (std::ostream& os, const Node<Value>& n)
	{
		os << "[" << n.getValue() << "]";
		return os;
	}
};

