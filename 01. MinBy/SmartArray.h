#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
class SmartArray {
private:
	size_t size;
	T* newArray;
public:
	/* Default Constructor */	SmartArray() :newArray(nullptr), size(0) {}
	/* Constructor */			SmartArray(size_t size) :size(size), newArray(size ? new T[size]{} : nullptr) {}
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

	/* Methods : */
	void print()const {
		for (size_t index = 0; index < size; index++) {
			std::cout << getValueByIndex(index) << ' ';
		}
		std::cout << std::endl;
	}
	void resize(const size_t& newSize) {
		if (newSize > 0) {
			this->operator= (this->ResizedSmartArray(newSize));
		}
		else {
			clear();
		}
	}

	/* Operators : */
	T& operator[](const size_t& index) {
		if (index < 0 or index >= this->size) {
			throw std::out_of_range("bad index");
		}
		return getValueByIndex(index);
	}
	/* Private Methods : */
private:
	T& getValueByIndex(const size_t& index) const {
		return *(newArray + index);
	}
	SmartArray ResizedSmartArray(const size_t& newSize) {
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
