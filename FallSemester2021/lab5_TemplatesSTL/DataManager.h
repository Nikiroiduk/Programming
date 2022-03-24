#pragma once
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cctype>

using std::vector;
using std::string;
using std::deque;
using std::ostream;
using std::ofstream;
using std::ifstream;

template <class T>
class DataManager
{
	friend ostream& operator<<(ostream& os, const DataManager<T>& dm) {
		for (T item : dm.data) {
			os << item << " ";
		}
		return os;
	}
private:
	vector<char> pMks = { '!', '%', '^', '&', '*',
						  '(', ')', '-', '+', '=',
						  '{', '}', '|', '~', '[',
						  ']', '\'', ';', ':', '\"',
						  '<', '>', '?', ',', '.', '\\', '#' };
	deque<T> data;
	void writeToDump();
	T loadFromDump();
public:
	void push(T elem);
	void push(T elems[], size_t n);
	T peek();
	T pop();
	char popLower();
	char popUpper();
};

