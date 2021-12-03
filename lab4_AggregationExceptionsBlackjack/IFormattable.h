#pragma once
#include <string>

using std::string;

class IFormattable {
public:
	virtual ~IFormattable() {};
	virtual string format() = 0;
};


