#ifndef _ArrayOfPointers_
#define _ArrayOfPointers_

#include "Company.h"
#include <vector>

class ArrayOfPointers {
private:
	std::vector <Company* > data;
public:
	void add(Company* ptrInput) {
		data.push_back(ptrInput);
	}
	size_t getSize() const {
		return data.size();
	}
	Company* get(size_t i) const {
		return data[i];
	}

	~ArrayOfPointers() {
		for (auto it = data.begin(); it != data.end(); it++) {
			delete* it;
		}
	}
};

#endif