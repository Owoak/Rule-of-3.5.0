#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"
#include <list>

void removeInvalid(std::list<Company*>& companies) {
	for (auto it = companies.begin(); it != companies.end();) {
		const Company& currentCompany = *(*it);
		if (currentCompany.getId() < 0) {
			delete* it;
			it = companies.erase(it);
		}
		else {
			it++;
		}
	}
}
#endif // !REMOVE_INVALID_H