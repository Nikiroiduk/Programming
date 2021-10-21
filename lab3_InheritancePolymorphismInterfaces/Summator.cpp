#include "Summator.h"

Summator::Summator() :
	ExpressionEvaluator() {
	symbol = '+';
}

Summator::Summator(int numOfOperands) :
	ExpressionEvaluator(numOfOperands) {
	symbol = '+';
}

double Summator::calculate() {
	double result = operands[0];

	for (int i = 1; i < numOfOperands; ++i) {
		result += operands[i];
	}

	return result;
}