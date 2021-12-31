#pragma once
#include <string>

using std::string;

class Book
{
private:
	string name;
	string author;
	int year;
public:
	Book(string name, string author, int year);
	string getName();
	string getAuthor();
	int getYear();
	bool operator<(const Book& b) const;
};

