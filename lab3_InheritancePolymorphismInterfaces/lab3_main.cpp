#include "Summator.h"
#include "Subtractor.h"
#include "Multiplier.h"
#include "Divisor.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionsEvaluator.h"

template<typename T>
void dynamicCastExercise1(const T& obj) {
	printf("\nShuffle(1, 2)\n");
	obj->logToScreen();
	printf("< Result %.2f >\n", obj->calculate());
	obj->shuffle(1, 2);
	obj->logToScreen();
	printf("< Result %.2f >\n", obj->calculate());
	printf("\nShuffle\n");
	obj->logToScreen();
	printf("< Result %.2f >\n", obj->calculate());
	obj->shuffle();
	obj->logToScreen();
	printf("< Result %.2f >\n", obj->calculate());
	delete obj;
}

void Exercise1() {
	const int numberOfElements = 5;
	ExpressionEvaluator* evaluators[numberOfElements];

	printf("=====Divisor=====\n");
	evaluators[0] = new Divisor(4);
	evaluators[0]->setOperand(0, 150);
	evaluators[0]->setOperand(1, -3);
	evaluators[0]->setOperand(2, 10);
	evaluators[0]->setOperand(3, -2.5);
	evaluators[0]->logToScreen();
	evaluators[0]->logToFile("log");
	printf("< Result %.2f >\n", evaluators[0]->calculate());

	printf("\n=====CustomExpressionEvaluator=====\n");
	evaluators[1] = new CustomExpressionsEvaluator(5);
	double CustomExpressionEvaluatorData[5]{ 5, 16, -3, 10, 12 };
	evaluators[1]->setOperands(CustomExpressionEvaluatorData, 5);
	evaluators[1]->logToScreen();
	evaluators[1]->logToFile("log");
	printf("< Result %.2f >\n", evaluators[1]->calculate());

	printf("\n=====Multiplier=====\n");
	evaluators[2] = new Multiplier(5);
	double MultiplierData[5]{ 1.5, 4, -2.5, - 8, -15 };
	evaluators[2]->setOperands(MultiplierData, 5);
	evaluators[2]->logToScreen();
	evaluators[2]->logToFile("log");
	printf("< Result %.2f >\n", evaluators[2]->calculate());

	printf("\n=====Summator=====\n");
	evaluators[3] = new Summator(5);
	double SummatorData[5]{ 1.5, 4, -2.5, -8, -15 };
	evaluators[3]->setOperands(SummatorData, 5);
	evaluators[3]->logToScreen();
	printf("-----Sort-----\n");
	evaluators[3]->sort();
	evaluators[3]->logToScreen();
	evaluators[3]->logToFile("log");
	printf("< Result %.2f >\n", evaluators[3]->calculate());

	printf("\n=====Subtractor=====\n");
	evaluators[4] = new Subtractor(5);
	double SubtractorData[5]{ 1.5, 4, -2.5, -8, -15 };
	evaluators[4]->setOperands(SubtractorData, 5);
	evaluators[4]->logToScreen();
	evaluators[4]->logToFile("log");
	printf("< Result %.2f >\n", evaluators[4]->calculate());

	printf("\n\n====Dynamic cast====");
	for (int i = 0; i < numberOfElements; ++i) {
		if (dynamic_cast<Divisor*>(evaluators[i])) {
			dynamicCastExercise1(dynamic_cast<Divisor*>(evaluators[i]));
		}
		else if (dynamic_cast<Subtractor*>(evaluators[i])) {
			dynamicCastExercise1(dynamic_cast<Subtractor*>(evaluators[i]));
		}
		else if (dynamic_cast<CustomExpressionsEvaluator*>(evaluators[i])) {
			dynamicCastExercise1(dynamic_cast<CustomExpressionsEvaluator*>(evaluators[i]));
		}
	}

	for (int i = 0; i < numberOfElements; ++i) {
		delete evaluators[i];
	}
}

int main() {
	/*
	Вид выражения CustomExpression : result = x1 + x2 * x3 + x4 * х5 + ...
	Порядок создания и инициализации объектов подклассов :
	Divisor: 4 операнда, присвоить поэлементно 150, -3, 10, –2.5.
	CustomExpressionEvaluator : 5 операндов, присвоить группой 5, 16, -3, 10, 12.
	Multiplier : 5 операндов, присвоить группой 1.5, 4, -2.5 - 8, -15.
	Метод shuffle() – отсортировать все операнды в порядке возрастания.
	      sort(), я не думаю что целесообразно наpывать метод который сортирует "смешиванием"
	Метод shuffle(size_t i, size_t j) – если хотя бы один из i - ого и j - ого операндов
	имеет дробную часть, поменять их местами, иначе – не менять.
	Формат вывода :
	5 + 16 * (-3) + 10 * 12 < Total 5 >
	< Result 77 >
	*/
	Exercise1();

	return 0;
}