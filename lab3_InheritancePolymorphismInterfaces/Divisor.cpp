#include "Divisor.h"

Divisor::Divisor() :
	ExpressionEvaluator() {
	symbol = '/';
}

Divisor::Divisor(int numOfOperands) :
	ExpressionEvaluator(numOfOperands) {
	symbol = '/';
}

double Divisor::calculate() {
	double result = operands[0];

	for (int i = 1; i < numOfOperands; ++i) {
		result /= operands[i];
	}

	return result;
}

void Divisor::shuffle() {
	for (int i = 0; i < numOfOperands; ++i)
		std::swap(operands[i], operands[std::rand() % numOfOperands]);
}

void Divisor::shuffle(size_t i, size_t j) {
	std::swap(operands[i], operands[j]);
}