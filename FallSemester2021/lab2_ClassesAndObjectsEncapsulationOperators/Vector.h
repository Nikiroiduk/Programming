#include "Matrix.h"
#pragma once
class Vector
{
private:
	int* array;
	int length;
	void initializeArray();
public:
	Vector(int length);
	void sort();
	void print();
	int& operator[] (const int index);
	Matrix convertToMatrix(int width, int height);
	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);
	~Vector();
};