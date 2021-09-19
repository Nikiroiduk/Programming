#pragma once
class Fraction
{
private:
public:
	double value;
	Fraction(double value);
	double get();
	int gcd(int x, int y);
	Fraction operator+(Fraction a);
	Fraction operator-(Fraction a);
	Fraction operator*(Fraction a);
	Fraction operator/(Fraction a);
};

