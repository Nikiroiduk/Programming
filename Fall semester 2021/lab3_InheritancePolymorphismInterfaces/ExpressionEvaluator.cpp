#include "ExpressionEvaluator.h"
#include <iostream>
#include <ios>
#include <fstream>
#include <chrono>

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

void ExpressionEvaluator::swap(size_t i, size_t j) {
	std::swap(operands[i], operands[j]);
}

void ExpressionEvaluator::sort() {
	int i, j;
	for (i = 0; i < numOfOperands - 1; i++)
		for (j = 0; j < numOfOperands - i - 1; j++)
			if (operands[j] > operands[j + 1])
				std::swap(operands[j], operands[j + 1]);
}

void ExpressionEvaluator::logToScreen() const {
	for (int i = 0; i < numOfOperands; i++) {
		printf(operands[i] < 0 ? " (%.2f) " : " %.2f ", operands[i]);
		printf(i == numOfOperands - 1 ? "" : "%c", symbol);
	}
	printf("\t< Total %d >\n", numOfOperands);
}

void ExpressionEvaluator::logToFile(const std::string& filename) const {
	printf("Logged to file\n");
	std::ofstream log(filename + ".txt", std::ios_base::app | std::ios_base::out);
	for (int i = 0; i < numOfOperands; ++i) {
		if (operands[i] < 0) log << "(" << operands[i] << ") " << (i == numOfOperands - 1 ? "" : &symbol) << " ";
		else log << operands[i] << " " << (i == numOfOperands - 1 ? "" : &symbol) << " ";
	}
	log << "\n";
}