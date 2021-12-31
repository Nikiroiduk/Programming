#pragma once
class Fraction
{
private:
	double value;
	int numerator;
	int denominator;
	int numberOfDecimalPlaces;
	int wholeFraction;
	int fractionalPartToInt(double number, double* integer, int decimalPlaces);
	int fractionalPartToInt(double number, double* integer);
	int getNumberOfDecimalPlaces(double value);
	int getNumberOfDecimalPlaces();
public:
	static int counter;
	void addFraction();
	static void printAsFraction(double decimalFraction);
	void printAsFraction();
	static void printAsFraction(Fraction fraction);
	static void printAsFraction(char* decimalFraction);
	static int gcd(int x, int y);
	void reduce();
	void setValue(double value);
	double getValue();
	Fraction(double value);
	~Fraction();
	Fraction operator+(Fraction a);
	Fraction operator-(Fraction a);
	Fraction operator*(Fraction a);
	Fraction operator/(Fraction a);
};

