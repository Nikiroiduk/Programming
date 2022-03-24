#pragma once
#include <string>

using std::string;

struct StringFinder {
	StringFinder(char el) {
		this->el = el;
	}
	bool operator()(string str) {
		return el == str.at(0);
	}
private:
	char el;
};