#include "Multiplier.h"

Multiplier::Multiplier() :
	ExpressionEvaluator() {
	symbol = '*';
}

Multiplier::Multiplier(int numOfOperands) :
	ExpressionEvaluator(numOfOperands) {
	symbol = '*';
}

double Multiplier::calculate() {
	double result = operands[0];

	for (int i = 1; i < numOfOperands; ++i) {
		result *= operands[i];
	}

	return result;
}