#include "Fraction.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

Fraction::Fraction(double value) {
	counter++;

	this->value = value;

    this->numberOfDecimalPlaces = getNumberOfDecimalPlaces();
	
	double wholeFraction;
	this->numerator = fractionalPartToInt(value, &wholeFraction);
	this->wholeFraction = (int)(wholeFraction);

	this->denominator = (int)(pow(10, numberOfDecimalPlaces));
}

void Fraction::setValue(double value) {
    this->value = value;
}

double Fraction::getValue() {
    return value;
}

int Fraction::fractionalPartToInt(double number, double* integer, int numberOfDecimalPlaces) {
	double frac = modf(number, &(*integer));
	return round(frac * pow(10, numberOfDecimalPlaces));
}

int Fraction::fractionalPartToInt(double number, double* integer) {
	double frac = modf(number, &(*integer));
	return round(frac * pow(10, numberOfDecimalPlaces));
}

int Fraction::getNumberOfDecimalPlaces() {
	int zeros = 0;
	std::stringstream ss;
	ss << std::setprecision(15) << value;
	std::string strNum = ss.str();
	size_t pos = strNum.find('.');
	if (pos != strNum.npos)
		zeros = strNum.size() - 1 - pos;
	return zeros;
}

int Fraction::getNumberOfDecimalPlaces(double value) {
	int zeros = 0;
	std::stringstream ss;
	ss << std::setprecision(15) << value;
	std::string strNum = ss.str();
	size_t pos = strNum.find('.');
	if (pos != strNum.npos)
		zeros = strNum.size() - 1 - pos;
	return zeros;
}

void Fraction::printAsFraction(double decimalFraction) {
	Fraction a = Fraction::Fraction(decimalFraction);
	a.reduce();
	a.printAsFraction();
}

void Fraction::printAsFraction(char* decimalFraction) {
	std::string str(decimalFraction);
	double decimalNumber = std::stod(str);

	Fraction a = Fraction::Fraction(decimalNumber);
	a.reduce();
	a.printAsFraction();
}

void Fraction::printAsFraction(Fraction fraction) {
	fraction.printAsFraction();
}

void Fraction::printAsFraction() {
	printf("\n\n%.0f %d/%d", wholeFraction, numerator, denominator);
}

void Fraction::reduce() {
	int gcdData = gcd(numerator, denominator);

	numerator /= gcdData;
	denominator /= gcdData;
}

int Fraction::gcd (int n1, int n2) {
    int tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}

Fraction Fraction::operator+(Fraction a) {
	counter++;
	return Fraction(this->value + a.getValue());
}

Fraction Fraction::operator-(Fraction a) {
	counter++;
	return Fraction(this->value - a.getValue());
}

Fraction Fraction::operator*(Fraction a) {
	counter++;
	return Fraction(this->value * a.getValue());
}

Fraction Fraction::operator/(Fraction a) {
	counter++;
	return Fraction(this->value / a.getValue());
}

Fraction::~Fraction() {
	counter--;
}