#include "Book.h"

Book::Book(string name, string author, int year) {
	this->name = name;
	this->author = author;
	this->year = year;
}

string Book::getName() {
	return name;
}

string Book::getAuthor() {
	return author;
}

int Book::getYear() {
	return year;
}

bool Book::operator<(const Book& b) const {
	if (author != b.author) return author < b.author;
	else return name < b.name;
}
