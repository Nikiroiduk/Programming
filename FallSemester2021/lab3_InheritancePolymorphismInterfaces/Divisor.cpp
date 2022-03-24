#include "Divisor.h"
#include <ctime>
#include <cmath>

Divisor::Divisor() :
	ExpressionEvaluator() {
	symbol = '/';
}

Divisor::Divisor(int numOfOperands) :
	ExpressionEvaluator(numOfOperands) {
	symbol = '/';
}

bool Divisor::containZeros() {
	for (int i = 0; i < numOfOperands; ++i) {
		if (operands[i] == 0) return true;
	}
	return false;
}

double Divisor::calculate() {
	if (containZeros()) return 0;

	double result = operands[0];

	for (int i = 1; i < numOfOperands; ++i) {
		result /= operands[i];
	}

	return result;
}

void Divisor::shuffle() {
	std::srand(std::time(nullptr));
	for (int i = 0; i < numOfOperands; ++i)
		std::swap(operands[i], operands[std::rand() % numOfOperands]);
}

void Divisor::shuffle(size_t i, size_t j) {
	float tmp;
	if (modf((float)operands[i], &tmp) != 0 || modf((float)operands[j], &tmp) != 0)
		std::swap(operands[i], operands[j]);
}