#include <fstream>

#include "Portfolio.h"

Portfolio::Portfolio() {
	head = tail = nullptr;
}

Portfolio::~Portfolio() {
	this->deleteAll();
}

void Portfolio::load(std::string filename) {
	this->deleteAll();

	std::ifstream is(filename);
	if (!is.is_open()) {
		std::cout << "Portfolio::load: ERROR: Cannot open file " << filename << " for reading";
		return;
	}

	Node n;
	while (is >> n) {
		if (n.valid()) {
			this->insertBack(new Node(n));
		}
	}
}

void Portfolio::save(std::string filename) {
	std::ofstream os(filename);
	if (!os.is_open()) {
		std::cout << "Portfolio::save: ERROR: Cannot open file " << filename << " for writing";
		return;
	} else {
		this->print(os);
	}
}

void Portfolio::insertFront(Node *n) {
	if (this->head == nullptr) {
		n->setNext(nullptr);
		n->setPrev(nullptr);
		this->head = this->tail = n;
	} else {
		n->setNext(this->head);
		n->setPrev(nullptr);
		this->head->setPrev(n);
		this->head = n;
	}
}

void Portfolio::insertMiddle(std::string afterSymbol, Node *nodeToInsert) {
	for (Node *n = this->head; n != nullptr; n = n->getNext()) {
		if (n->getS().getSymbol() == afterSymbol) {
			if (n == this->tail) {
				this->insertBack(nodeToInsert);
			} else {
				Node* oldNext = n->getNext();
				n->setNext(nodeToInsert);
				nodeToInsert->setNext(oldNext);
				nodeToInsert->setPrev(n);
				oldNext->setPrev(nodeToInsert);
			}
		}
	}
}

void Portfolio::insertBack(Node *n) {
	if (this->tail == nullptr) {
		n->setNext(nullptr);
		n->setPrev(nullptr);
		this->head = this->tail = n;
	} else {
		n->setNext(nullptr);
		n->setPrev(this->tail);
		this->tail->setNext(n);
		this->tail = n;
	}
}

void Portfolio::deleteAll() {
	while (this->head != nullptr) {
		Node *oldHead = this->head;
		this->head = this->head->getNext();
		delete oldHead;
	}
}

void Portfolio::print(std::ostream& os) {
	for (Node * n = this->head; n != nullptr; n = n->getNext()) {
		os << (*n) << std::endl;
	}
}

void Portfolio::printReverse(std::ostream& os) {
	for (Node * n = this->tail; n != nullptr; n = n->getPrev()) {
		os << (*n) << std::endl;
	}
}
