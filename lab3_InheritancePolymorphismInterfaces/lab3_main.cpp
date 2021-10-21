#include "Summator.h"
#include "Subtractor.h"
#include "Multiplier.h"
#include "Divisor.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionsEvaluator.h"
int main() {
	ExpressionEvaluator* evaluators[5];

	evaluators[0] = new Summator(4);
	evaluators[0]->logToScreen();
	double ops[]{ 1, 2, 3, -4 };
	evaluators[0]->setOperands(ops, 4);
	evaluators[0]->logToScreen();
	printf("< Result %.2f >\n", evaluators[0]->calculate());

	evaluators[1] = new Subtractor();
	evaluators[1]->logToScreen();
	evaluators[1]->setOperands(ops, 4);
	evaluators[1]->logToScreen();
	printf("< Result %.2f >\n", evaluators[1]->calculate());

	evaluators[2] = new Multiplier(4);
	evaluators[2]->logToScreen();
	evaluators[2]->setOperands(ops, 4);
	evaluators[2]->logToScreen();
	printf("< Result %.2f >\n", evaluators[2]->calculate());

	evaluators[3] = new Divisor(4);
	evaluators[3]->logToScreen();
	evaluators[3]->setOperands(ops, 4);
	evaluators[3]->logToScreen();
	printf("< Result %.2f >\n", evaluators[3]->calculate());

	printf("\n\n====Dynamic cast====\n");
	for (int i = 0; i < 4; ++i) {
		if (dynamic_cast<Divisor*>(evaluators[i])) {
			Divisor* tmpDiv = dynamic_cast<Divisor*>(evaluators[i]);
			tmpDiv->logToScreen();
			printf("< Result %.2f >\n", tmpDiv->calculate());
			tmpDiv->shuffle();
			tmpDiv->logToScreen();
			printf("< Result %.2f >\n", tmpDiv->calculate());
		}
		else if (dynamic_cast<Subtractor*>(evaluators[i])) {
			Subtractor* tmpSub = dynamic_cast<Subtractor*>(evaluators[i]);
			tmpSub->logToScreen();
			printf("< Result %.2f >\n", tmpSub->calculate());
			tmpSub->shuffle();
			tmpSub->calculate();
			tmpSub->logToScreen();
			printf("< Result %.2f >\n", tmpSub->calculate());
		}
	}

	for (int i = 0; i < 4; ++i) {
		delete evaluators[i];
	}
	return 0;
}