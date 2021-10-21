#include "CustomExpressionsEvaluator.h"

//TODO: Переписывать эту чушь
// 
//x1 + x2 * x3 + x4 * x5 + ...
//double CustomExpressionsEvaluator::calculate() { 
//	int count = 0;
//	std::vector<double> sum;
//	if (numOfOperands % 2 == 0) {
//		sum.push_back(operands[0]);
//		sum.push_back(operands[numOfOperands - 1]);
//		count = numOfOperands / 2 - 1;
//	}
//	else {
//		sum.push_back(operands[0]);
//		count = numOfOperands / 2;
//	}
//	for (int i = 0; i < count; ++i) {
//		Multiplier m(2);
//		m.setOperand(0, operands[i + 1]);
//		m.setOperand(1, operands[i + 2]);
//		sum.push_back(m.calculate());
//	}
//	Summator s(sum.capacity());
//	double* tmp = new double[sum.capacity()];
//	for (int i = 0; i < sum.capacity(); ++i) {
//		tmp[i] = sum[i];
//	}
//	s.setOperands(tmp, sum.capacity());
//	return s.calculate();
//}
//
//CustomExpressionsEvaluator::CustomExpressionsEvaluator() : ExpressionEvaluator() {}
//CustomExpressionsEvaluator::CustomExpressionsEvaluator(int numOfOperands) : ExpressionEvaluator(numOfOperands) {}