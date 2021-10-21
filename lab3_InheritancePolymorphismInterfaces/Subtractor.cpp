#include "Subtractor.h"

Subtractor::Subtractor() :
	ExpressionEvaluator() {
	symbol = '-';
}

Subtractor::Subtractor(int numOfOperands) :
	ExpressionEvaluator(numOfOperands) {
	symbol = '-';
}

double Subtractor::calculate() {
	double result = operands[0];

	for (int i = 1; i < numOfOperands; ++i) {
		result -= operands[i];
	}

	return result;
}

void Subtractor::shuffle() {
	for (int i = 0; i < numOfOperands; ++i)
		std::swap(operands[i], operands[std::rand() % numOfOperands]);
}

void Subtractor::shuffle(size_t i, size_t j) {
	std::swap(operands[i], operands[j]);
}