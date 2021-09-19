#pragma once
class Matrix
{
private:
	int** array;
	int width;
	int height;
public:
	Matrix();
	Matrix(int width, int height);
	Matrix(int* array1D, int width, int height);
	int at(int i, int j) const;
	void setAt(int i, int j, int value);
	void print();
	Matrix& operator++();
	Matrix& operator--();
	Matrix operator++(int);
	Matrix operator--(int);
	~Matrix();
};