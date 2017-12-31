#pragma once

template<class T>
class ListNode
{
private:
	ListNode<T>& operator=(const ListNode<T>&);
public:
	T data;
	ListNode<T> * next;
	ListNode<T>(const T& d) : data(d), next() {}
	ListNode<T>(const ListNode<T>& copyNode) : data(copyNode.data), next() {}

};

template<class T>
class List {
public:

	ListNode<T> * head;

	List() : head(NULL) {}
	List(ListNode<T> * newNode) : head(newNode) {}
	~List()
	{
		ListNode<T> * curr = head;
		while (head) {
			head = head->next;
			delete curr;
			curr = head;
		}
	}

	void insert(T val)
	{
		ListNode<T> * newNode = new ListNode<T>(val);
		newNode->next = head;
		head = newNode;
	}

	friend std::ostream& operator<< (std::ostream& os, const List<T>& l)
	{
		for (auto n = l.head; n != nullptr; n = n->next) {
			os << n->data << "\n";
		}
		return os;
	}

};
