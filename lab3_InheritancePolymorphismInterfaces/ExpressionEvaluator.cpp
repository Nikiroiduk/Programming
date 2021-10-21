#include "ExpressionEvaluator.h"
#include <iostream>

ExpressionEvaluator::ExpressionEvaluator(int numOfOperands) {
	this->numOfOperands = numOfOperands;
	operands = new double[numOfOperands] {0};
	initializeZeros();
}

ExpressionEvaluator::ExpressionEvaluator() {
	this->numOfOperands = 20;
	operands = new double[20] {0};
	initializeZeros();
}

ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] operands;
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {
	operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (int i = 0; i < n; ++i) {
		operands[i] = ops[i];
	}
}

void ExpressionEvaluator::initializeZeros() {
	for (int i = 0; i < numOfOperands; ++i) {
		operands[i] = 0;
	}
}

void ExpressionEvaluator::logToScreen() const {
	for (int i = 0; i < numOfOperands; i++) {
		printf(operands[i] < 0 ? " (%.2f) " : " %.2f ", operands[i]);
		printf(i == numOfOperands - 1 ? "" : "%c", symbol);
	}
	printf("\t< Total %d >\n", numOfOperands);
}

void ExpressionEvaluator::logToFile(const std::string& filename) const {
	printf("Logged to file");
}