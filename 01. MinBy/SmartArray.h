#pragma once

template <typename T>
class SmartArray {
private:
	size_t size;
	T* newArray;
public:
	/* Default Constructor */	SmartArray() :newArray(nullptr) {}
	/* Constructor */			SmartArray(size_t size) :size(size), newArray(size ? new T[size]{} : nullptr) {}
	/* Destructor */			~SmartArray() { delete[]newArray; }
	/* CopyConstructor */
	/* CopyOperator */

	/* Methods : */

	void print()const {
	}

	/* Operators : */
	T& operator[](size_t index) {
		return *(newArray + index);
	}
};