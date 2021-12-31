#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>

typedef std::pair<std::string, int> pair;

using std::ostream;
using std::string;
using std::map;
using std::ifstream;
using std::vector;
using std::back_inserter;
using std::copy;
using std::endl;

class TextAnalyzer
{
	friend ostream& operator<<(ostream& os, const TextAnalyzer& Ta) {
		for (auto const& pair : Ta.vec) {
			if (pair.second >= 7) os << pair.first << " - " << pair.second << endl;
			else break;
		}
		return os;
	}
private:
	vector<pair> vec;
	string path;
	map<string, int> dict;
	void analyzeFile();
	void sort();
public:
	TextAnalyzer(const string& path);
};

