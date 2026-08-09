#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"
#include <memory>

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& properties) {
	int id = std::stoi(properties[0]);
	std::string name = properties[1];

	std::vector<std::pair<char, char>> employees;

	for (int i = 2; i < properties.size(); i++) {
		std::string initials = properties[i];
		if (initials.length() >= 2) {
			employees.push_back(std::make_pair(initials[0], initials[1]));
		}
	}

	return std::make_shared<Company>(id, name, employees);
}

#endif // !MAKE_COMPANY_HCompany();
