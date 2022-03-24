#include "Matrix.h"
#include <stdio.h>
Matrix::Matrix(int width, int height) {
	this->width = width;
	this->height = height;

	array = new int* [height];
	for (int i = 0; i < height; i++) {
		*(array + i) = new int[width];
	}
}

Matrix::Matrix(int* array1D, int width, int height) {
	//copy paste from ctr!!!
	this->width = width;
	this->height = height;

	array = new int* [height];
	for (int i = 0; i < height; i++) {
		*(array + i) = new int[width];
	}
	//

	for (int i = 0, count = 0; i < height; i++) {
		for (int j = 0; j < width; j++, count++) {
			*(*(array + i) + j) = *(array1D + count);
		}
	}
}

void Matrix::print() {
	printf("\n[");
	for (int i = 0; i < height; i++) {
		printf(i == 0 ? "" : "\n");
		for (int j = 0; j < width; j++) {
			printf("%5d", *(*(array + i) + j));
		}
	}
	printf("]");
}

int Matrix::at(int i, int j) const {
	return *(*(array + i) + j);
}

void Matrix::setAt(int i, int j, int value) {
	*(*(array + i) + j) = value;
}

//prefix
Matrix& Matrix::operator++() {
	for (int i = 0, count = 0; i < height; i++) {
		for (int j = 0; j < width; j++, count++) {
			++(*(*(array + i) + j));
		}
	}
	return *this;
}

Matrix& Matrix::operator--() {
	for (int i = 0, count = 0; i < height; i++) {
		for (int j = 0; j < width; j++, count++) {
			--(*(*(array + i) + j));
		}
	}
	return *this;

}

//postfix
Matrix Matrix::operator++(int) {
	for (int i = 0, count = 0; i < height; i++) {
		for (int j = 0; j < width; j++, count++) {
			(*(*(array + i) + j))++;
		}
	}
	return Matrix(1, 1);
}

Matrix Matrix::operator--(int) {
	for (int i = 0, count = 0; i < height; i++) {
		for (int j = 0; j < width; j++, count++) {
			(*(*(array + i) + j))--;
		}
	}
	return Matrix(1, 1);
}

Matrix::~Matrix() {
	for (int i = 0; i < width; i++) {
		delete[] *(array + i);
	}
	delete[] array;
}