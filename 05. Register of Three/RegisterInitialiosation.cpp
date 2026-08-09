#include "Register.h"
#include <algorithm>

Register::Register(size_t numCompanies) : companiesArray(new Company[numCompanies]), numAdded(0) {}

void Register::add(const Company& c) {
	companiesArray[numAdded] = c;
	numAdded++;
}

Company Register::get(int companyId) const {
	Company* foundAt = std::find_if(companiesArray, companiesArray + numAdded, [&companyId](const Company& currentCompany) {if (currentCompany.getId() == companyId) { return true; } else { return false; }});
	if (foundAt != (companiesArray + numAdded)) {
		return *foundAt;
	}
	else {
		return Company();
	}
}

Register::~Register() {
	if (companiesArray != nullptr) { delete[] companiesArray; }
}

Register& Register::operator=(const Register& other) {
	if (this != &other) {
		if (this->companiesArray != nullptr) {
			delete[]this->companiesArray;
		}
		this->numAdded = other.numAdded;
		if (other.numAdded != 0) {
			this->companiesArray = new Company[other.numAdded];
			std::copy(other.companiesArray, other.companiesArray + other.numAdded, this->companiesArray);
		}
		else {
			this->companiesArray = nullptr;
		}
	}
	return *this;
}

Register::Register(const Register& other) :numAdded(other.numAdded), companiesArray(numAdded ? new Company[numAdded]{} : nullptr) {
	if (companiesArray != nullptr) {
		std::copy(other.companiesArray, other.companiesArray + other.numAdded, this->companiesArray);
	}
}