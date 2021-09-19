#pragma once
class Vector
{
private:
	int* array;
	int length;
public:
	Vector(int length);
	void sort();
	void print();
	int& operator[] (const int index);
	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);
	~Vector();
};