#pragma once
#include <algorithm>
#include <iostream>

typedef size_t Index;

template <typename T>
class SmartArray {
private:
	Index size;
	T* newArray;
public:
	/* Default Constructor */	SmartArray() :newArray(nullptr), size(0) {}
	/* Constructor */			SmartArray(Index size) :size(size), newArray(size ? new T[size]{} : nullptr) {}
	/* Destructor */			~SmartArray() { if (size != 0) { delete[]newArray; } }
	/* CopyConstructor */
	SmartArray(const SmartArray& other) :size(other.size), newArray(size ? new T[size]{} : nullptr) {
		std::copy(other.newArray, other.newArray + other.size, this->newArray);
	}
	/* CopyOperator */
	SmartArray& operator=(const SmartArray& other) {
		if (this != &other) {
			this->clear();
			this->size = other.size;
			if (this->size > 0) {
				this->newArray = new T[other.size]{};
				std::copy(other.newArray, other.newArray + other.size, this->newArray);
			}
		}
		return *this;
	}
	/* MoveConstructor */
	SmartArray(SmartArray&& other) :size(other.size), newArray(other.newArray) {
		other.clear();
	}
	/* MoveOperator */
	SmartArray& operator= (SmartArray&& other) {
		if (this != &other) {
			this->clear();
			this->size = other.size;
			this->newArray = other.newArray;
			other.newArray = nullptr;
			other.size = 0;
		}
	}

	/* Methods : */
	void print()const {
		for (Index index = 0; index < size; index++) {
			std::cout << getValueByIndex(index) << ' ';
		}
		std::cout << std::endl;
	}
	void resize(const Index& newSize) {
		if (newSize > 0) {
			*this = std::move(this->ResizedSmartArray(newSize));
		}
		else {
			clear();
		}
	}

	/* Operators : */
	T& operator[](const Index& index) {
		if (index < 0 or index >= this->size) {
			throw std::out_of_range("bad index");
		}
		return getValueByIndex(index);
	}

	/* Iterators Class : */
	class Iterators {
	private:
		Index index;
		SmartArray* array;
	public:
		Iterators(const Index& index, SmartArray* array) :index(index), array(array) {}
		T& operator*() {
			return (*array)[index];
		}
		Iterators& operator++() {
			this->index++;
			return *this;
		}
		bool operator !=(const Iterators& other) {
			return this->index != other.index;
		}
	};

	Iterators begin() { return Iterators(0, this); }
	Iterators end() { return Iterators(this->size, this); }

	/* Private Methods : */
private:
	T& getValueByIndex(const Index& index) const {
		return *(newArray + index);
	}
	SmartArray ResizedSmartArray(const Index& newSize) {
		SmartArray resizedArr(newSize);
		for (size_t index = 0; index < newSize and index < this->size; index++) {
			resizedArr[index] = (*this)[index];
		}
		return resizedArr;
	}
	void clear() {
		if (this->size > 0) {
			delete[] this->newArray;
			this->newArray = nullptr;
			size = 0;
		}
	}
};