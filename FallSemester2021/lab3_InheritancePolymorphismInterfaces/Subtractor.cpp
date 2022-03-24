#include "Subtractor.h"
#include <ctime>
#include <cmath>

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
	std::srand(std::time(nullptr));
	for (int i = 0; i < numOfOperands; ++i)
		std::swap(operands[i], operands[std::rand() % numOfOperands]);
}

void Subtractor::shuffle(size_t i, size_t j) {
	float tmp;
	if (modf((float)operands[i], &tmp) != 0 || modf((float)operands[j], &tmp) != 0)
		std::swap(operands[i], operands[j]);
}