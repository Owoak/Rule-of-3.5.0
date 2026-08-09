#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <unordered_set>

std::pair <int, std::string> seperateLine(const std::string& line) {
	std::istringstream seperatedLine(line);
	int id; std::string name;
	seperatedLine >> id >> name;

	return std::pair <int, std::string> {id, name};
}

Company* parseUniqueCompanies(const std::string& input, int& numCompanies, std::string(*comparator)(const Company& c)) {
	numCompanies = std::count(input.begin(), input.end(), '\n');
	Company* const array = new Company[numCompanies];
	std::unordered_set <std::string> Uniqueness;
	std::istringstream buffer(input);

	std::string line; size_t index = 0;
	while (getline(buffer, line) and line != "end") {
		std::pair <int, std::string> SeperatedLine = seperateLine(line);
		Company currentCompany(SeperatedLine.first, SeperatedLine.second);
		if (Uniqueness.insert(comparator(currentCompany)).second) {
			*(array + index) = currentCompany;
			index++;
		}
		else {
			numCompanies--;
		}
	}
	return array;
}

#endif // !PARSE_COMPANIES_H