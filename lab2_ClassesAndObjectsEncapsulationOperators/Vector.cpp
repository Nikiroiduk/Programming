#include "Vector.h"
#include <cmath>
#include <stdio.h>

Vector::Vector(int length)
{
	this->length = length;
	array = new int[length];
	for (int i = 0; i < length; i++) {
		*(array + i) = ((i + 1) % 2 == 0 ? -(pow(i, 2) + 1) : pow(i, 2) + 1);
	}
}

void Vector::sort() {
	int i, key, j;
	for (i = 1; i < length; i++)
	{
		key = *(array + i);
		j = i - 1;

		while (j >= 0 && *(array + j) < key)
		{
			*(array + (j + 1)) = *(array + j);
			j = j - 1;
		}
		*(array + (j + 1)) = key;
	}
}

void Vector::print() {
	printf("\n[");
	for (int i = 0; i < length; i++) {
		printf("%5d", *(array + i));
	}
	printf("]");
}

//prefix
Vector& Vector::operator++() {
	for (int i = 0; i < length; i++) {
		++(*(array + i));
	}
	return *this;
}

Vector& Vector::operator--() {
	for (int i = 0; i < length; i++) {
		--(*(array + i));
	}
	return *this;

}

//postfix
Vector Vector::operator++(int) {
	for (int i = 0; i < length; i++) {
		(*(array + i))++;
	}
	return 0;
}

Vector Vector::operator--(int) {
	for (int i = 0; i < length; i++) {
		(*(array + i))--;
	}
	return 0;
}

int& Vector::operator[] (const int index)
{
	return array[index];
}
	
Vector::~Vector() {
	delete[] array;
}