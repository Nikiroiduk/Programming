#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "StringFinder.cpp"

using std::ostream;
using std::exception;
using std::vector;
using std::find;
using std::find_if;
using std::string;
using std::cout;
using std::endl;

template <class T>
class Cache
{
	friend ostream& operator<<(ostream& os, const Cache& ch) {
		for (auto const& item : ch.data) {
			os << item << " ";
		}
		return os;
	}
private:
	vector<T> data;
public:
	void put(T elem);
	T operator+=(const T& elem);
	bool contains(T elem);
};

