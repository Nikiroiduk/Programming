#include "CustomExpressionsEvaluator.h"
#include "Multiplier.h"
#include "Summator.h"
#include <ctime>
#include <cmath>
#include <vector>

double CustomExpressionsEvaluator::calculate() {
	Multiplier m(2);
	bool ev = 0;
	std::vector<double> sum;
	//the first element is always added
	sum.push_back(operands[0]);
	//the last element is added when the total number of elements is even
	if (numOfOperands % 2 == 0) sum.push_back(operands[numOfOperands - 1]);

	for (int i = 1; i < numOfOperands; i += 2) {
		m.setOperand(0, operands[i]);
		m.setOperand(1, operands[i + 1]);
		sum.push_back(m.calculate());
	}

	Summator s(sum.capacity());
	s.setOperands(sum.data(), sum.capacity());

	return s.calculate();
}

void CustomExpressionsEvaluator::logToScreen() const {
	bool ev = 0;
	for (int i = 0; i < numOfOperands; ++i) {
		ev = !ev;
		//"beautiful"
		printf(operands[i] < 0 ?
			   i == numOfOperands - 1 ? ev ? "(%.2f)" : "(%.2f)" : ev ? "(%.2f) + " : "(%.2f) * " :
			   i == numOfOperands - 1 ? ev ? "%.2f" : "%.2f" : ev ? "%.2f + " : "%.2f * ",
			   operands[i]);
	}
	printf("\t< Total %d >\n", numOfOperands);
}

void CustomExpressionsEvaluator::shuffle() {
	std::srand(std::time(nullptr));
	for (int i = 0; i < numOfOperands; ++i)
		std::swap(operands[i], operands[std::rand() % numOfOperands]);
}

void CustomExpressionsEvaluator::shuffle(size_t i, size_t j) {
	float tmp;
	if (modf((float)operands[i], &tmp) != 0 || modf((float)operands[j], &tmp) != 0)
		std::swap(operands[i], operands[j]);
}

CustomExpressionsEvaluator::CustomExpressionsEvaluator() : ExpressionEvaluator() {}

CustomExpressionsEvaluator::CustomExpressionsEvaluator(int numOfOperands) : ExpressionEvaluator(numOfOperands) {}