#ifndef MIN_BY_H
#define MIN_BY_H
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string minBy(std::vector<std::string> words, bool (*comparator)(const std::string& a, const std::string& b)) {
	std::sort(words.begin(), words.end(), comparator);
	return words[0];
}

#endif // !MIN_BY_H