#include "Fraction.h"

Fraction::Fraction(double value) {
	this->value = value;
}

//TODO:
int Fraction::gcd(int x, int y) {
	return 0;
}

Fraction Fraction::operator+(Fraction a) {
	return Fraction(this->value + a.value);
}

Fraction Fraction::operator-(Fraction a) {
	return Fraction(this->value - a.value);
}

Fraction Fraction::operator*(Fraction a) {
	return Fraction(this->value * a.value);
}

Fraction Fraction::operator/(Fraction a) {
	return Fraction(this->value / a.value);
}