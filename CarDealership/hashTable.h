#pragma once
#include <cstddef>
#include <string>

#include "node.h"

const int HASH_TABLE_SIZE = 10;

template <typename Value>
class HashTable
{
private:

	HashTable(const HashTable & other);
	const HashTable & operator=(const HashTable & other);

	unsigned long hashFunc(const std::string &s) const {
		unsigned int b = 378551;
		unsigned int a = 63689;
		unsigned int hash = 0;

		for (std::size_t i = 0; i < s.length(); i++) {
			hash = hash * a + s[i];
			a = a * b;
		}
		return hash % HASH_TABLE_SIZE;
	}

public:
	Node<Value> *table[HASH_TABLE_SIZE];

	HashTable() : table() {};

	~HashTable()
	{
		for (auto i = 0; i < HASH_TABLE_SIZE; i++) {
			Node<Value> *node = table[i];

			while (node != nullptr) {
				Node<Value> *toDelete = node;
				node = node->getNext();
				delete toDelete;
			}

			table[i] = nullptr;
		}
	}

	bool get(const std::string &key, Value &value)
	{
		auto hashValue = hashFunc(key);

		for (auto node = table[hashValue]; node != nullptr; node= node->getNext()) {
			if (node->getKey() == key) {
				value = node->getValue();
				return true;
			}
		}

		return false;
	}

	void put(const std::string &key, const Value &value)
	{
		auto hashValue = hashFunc(key);
		Node<Value> *prev = nullptr;
		Node<Value> *node = nullptr;

		for (node =table[hashValue]; node != nullptr && node->getKey() != key; node = node->getNext()) {
			prev = node;
		}

		if (node == nullptr) {
			node = new Node<Value>(key, value);

			if (prev == nullptr) {
				// insert as first bucket
				table[hashValue] = node;
			} else {
				prev->setNext(node);
			}
		} else {
			// just update the value
			node->setValue(value);
		}
	}

	bool remove(const std::string &key)
	{
		auto hashValue = hashFunc(key);
		Node<Value> *prev = nullptr;
		Node<Value> *node = table[hashValue];

		for (auto node = table[hashValue]; node != nullptr && node->getKey() != key; node = node->getNext()) {
			prev = node;
		}

		if (node == nullptr) {
			return false; // not found
		} else {
			if (prev == nullptr) {
				// remove first bucket of the list
				table[hashValue] = node->getNext();
			} else {
				prev->setNext(node->getNext());
			}
			delete node;
			return true;
		}
	}

	friend std::ostream& operator<< (std::ostream& os, const HashTable<Value>& h)
	{
		for (auto i = 0; i < HASH_TABLE_SIZE; i++) {
			bool printThis = (h.table[i] != nullptr);

			if (printThis) { os << "[" << i << "]"; }

			for (auto node = h.table[i]; node != nullptr; node = node->getNext()) {
				os << "[" << *node << "] ";
			}

			if (printThis) { os << std::endl; }
		}

		return os;
	}
};
