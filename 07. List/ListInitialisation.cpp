#include "List.h"
#include <sstream>

// ---------- Node ----------

List::Node::Node(int value, Node* prev, Node* next)
	: value(value), prev(prev), next(next) {
}

int List::Node::getValue() const { return value; }
void List::Node::setValue(int value) { this->value = value; }

List::Node* List::Node::getNext() const { return next; }
void List::Node::setNext(Node* next) { this->next = next; }

List::Node* List::Node::getPrev() const { return prev; }
void List::Node::setPrev(Node* prev) { this->prev = prev; }

// ---------- List ----------

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
	Node* cur = other.head;
	while (cur != nullptr) {
		Node* n = new Node(cur->getValue(), tail, nullptr);
		if (tail != nullptr) {
			tail->setNext(n);
		}
		else {
			head = n;
		}
		tail = n;
		++size;
		cur = cur->getNext();
	}
}

int List::first() const {
	return head->getValue();
}

void List::add(int value) {
	Node* n = new Node(value, tail, nullptr);
	if (tail != nullptr) {
		tail->setNext(n);
	}
	else {
		head = n;
	}
	tail = n;
	++size;
}

void List::addAll(const List& other) {
	Node* cur = other.head;
	while (cur != nullptr) {
		add(cur->getValue());
		cur = cur->getNext();
	}
}

void List::removeFirst() {
	if (head == nullptr) return;

	Node* old = head;
	head = head->getNext();

	if (head != nullptr) {
		head->setPrev(nullptr);
	}
	else {
		tail = nullptr;
	}

	delete old;
	--size;
}

void List::removeAll() {
	Node* cur = head;
	while (cur != nullptr) {
		Node* next = cur->getNext();
		delete cur;
		cur = next;
	}
	head = nullptr;
	tail = nullptr;
	size = 0;
}

size_t List::getSize() const { return size; }
bool List::isEmpty() const { return size == 0; }

List List::getReversed(List l) {
	List result;
	Node* cur = l.tail;
	while (cur != nullptr) {
		result.add(cur->getValue());
		cur = cur->getPrev();
	}
	return result;
}

std::string List::toString() const {
	std::ostringstream oss;

	Node* cur = head;
	while (cur != nullptr) {
		oss << cur->getValue();
		if (cur->getNext() != nullptr) oss << ' ';
		cur = cur->getNext();
	}

	return oss.str();
}

List& List::operator<<(const int& value) {
	add(value);
	return *this;
}

List& List::operator<<(const List& other) {
	addAll(other);
	return *this;
}

List& List::operator=(const List& other) {
	if (this == &other) return *this;

	Node* cur = head;
	while (cur != nullptr) {
		Node* next = cur->getNext();
		delete cur;
		cur = next;
	}
	head = nullptr;
	tail = nullptr;
	size = 0;

	cur = other.head;
	while (cur != nullptr) {
		Node* n = new Node(cur->getValue(), tail, nullptr);
		if (tail != nullptr) {
			tail->setNext(n);
		}
		else {
			head = n;
		}
		tail = n;
		++size;
		cur = cur->getNext();
	}

	return *this;
}

List::~List() {
	Node* cur = head;
	while (cur != nullptr) {
		Node* next = cur->getNext();
		delete cur;
		cur = next;
	}
}