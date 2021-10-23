#include "Summator.h"
#include "Subtractor.h"
#include "Multiplier.h"
#include "Divisor.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionsEvaluator.h"
#include "HouseholdDevice.h"
#include "Conditioner.h"
#include "Heater.h"

template<typename T>

//Method for objects that implements IShuffle
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
	printf("< Result %.2f >\n", evaluators[0]->calculate());
	evaluators[0]->logToFile("log");

	printf("\n=====CustomExpressionEvaluator=====\n");
	evaluators[1] = new CustomExpressionsEvaluator(5);
	double CustomExpressionEvaluatorData[5]{ 5, 16, -3, 10, 12 };
	evaluators[1]->setOperands(CustomExpressionEvaluatorData, 5);
	evaluators[1]->logToScreen();
	printf("< Result %.2f >\n", evaluators[1]->calculate());
	evaluators[1]->logToFile("log");

	printf("\n=====Multiplier=====\n");
	evaluators[2] = new Multiplier(5);
	double MultiplierData[5]{ 1.5, 4, -2.5, - 8, -15 };
	evaluators[2]->setOperands(MultiplierData, 5);
	evaluators[2]->logToScreen();
	printf("< Result %.2f >\n", evaluators[2]->calculate());
	evaluators[2]->logToFile("log");

	printf("\n=====Summator=====\n");
	evaluators[3] = new Summator(5);
	double SummatorData[5]{ 1.5, 4, -2.5, -8, -15 };
	evaluators[3]->setOperands(SummatorData, 5);
	evaluators[3]->logToScreen();
	printf("-----Sort-----\n");
	evaluators[3]->sort();
	evaluators[3]->logToScreen();
	printf("< Result %.2f >\n", evaluators[3]->calculate());
	evaluators[3]->logToFile("log");

	printf("\n=====Subtractor=====\n");
	evaluators[4] = new Subtractor(5);
	double SubtractorData[5]{ 1.5, 4, -2.5, -8, -15 };
	evaluators[4]->setOperands(SubtractorData, 5);
	evaluators[4]->logToScreen();
	printf("< Result %.2f >\n", evaluators[4]->calculate());
	evaluators[4]->logToFile("log");

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

void Exercise2() {
	const int numberOfDevices = 3;
	HouseholdDevice* devices[numberOfDevices];

	printf("=====Conditioner 1=====");
	devices[0] = new Conditioner("Nord", "DBL_2875", 30, 50, "2007");
	devices[0]->printState();
	dynamic_cast<Conditioner*>(devices[0])->control(25);
	devices[0]->printState();
	dynamic_cast<Conditioner*>(devices[0])->control(15);
	devices[0]->printState();
	dynamic_cast<Conditioner*>(devices[0])->control(45);
	devices[0]->printState();
	devices[0]->serialize();
	devices[0]->deserialize();
	
	printf("\n\n=====Conditioner 2=====");
	devices[1] = new Conditioner();
	devices[1]->setFirm("Donbass");
	devices[1]->setModel("ASdk");
	devices[1]->setTemp(40);
	devices[1]->setMass(88);
	devices[1]->setReleaseYear("1997");
	devices[1]->printState();
	dynamic_cast<Conditioner*>(devices[1])->control(35);
	devices[1]->printState();
	
	printf("\n=====Heater 1=====");
	devices[2] = new Heater("Lasko", "Space heater", 20, 20, "2020");
	devices[2]->printState();
	dynamic_cast<Heater*>(devices[2])->control(30);
	devices[2]->printState();
	dynamic_cast<Heater*>(devices[2])->control(50);
	devices[2]->printState();

	//Something went wrong... again
	//Exactly the same construction in the first exercise works fine ¯\_(ツ)_/¯
	for (int i = 0; i < numberOfDevices; ++i) {
		delete devices[i];
	}
	printf("I am an output that will never happen ):");

}				  

int main() {
	/*
	Вид выражения CustomExpression : result = x1 + x2 * x3 + x4 * х5 + ...
	Порядок создания и инициализации объектов подклассов :
	Divisor: 4 операнда, присвоить поэлементно 150, -3, 10, –2.5.
	CustomExpressionEvaluator : 5 операндов, присвоить группой 5, 16, -3, 10, 12.
	Multiplier : 5 операндов, присвоить группой 1.5, 4, -2.5 - 8, -15.
	Метод shuffle() – отсортировать все операнды в порядке возрастания.
	      sort(), я не думаю что целесообразно называть метод который сортирует "смешиванием"
	Метод shuffle(size_t i, size_t j) – если хотя бы один из i - ого и j - ого операндов
	имеет дробную часть, поменять их местами, иначе – не менять.
	Формат вывода :
	5 + 16 * (-3) + 10 * 12 < Total 5 >
	< Result 77 >
	*/
	Exercise1();

	/*
	Класс КОНДИЦИОНЕР + классы БЫТОВОЕ УСТРОЙСТВО, ОБОГРЕВАТЕЛЬ.
	Реализовать схему наследования классов и корректно распределить по классам данные :
	фирма, модель, вес, температура, режим, год выпуска, мощность.
	Интерфейс возможности управления / регулировки устройства IControllable с
	методом void control(int temperature) – отрегулировать устройство в зависимости
	от установленной в параметре температуры.Реализация метода в классе кондиционера :
	если температура задана меньше 10 градусов, то выдать сообщение и выключиться,
	иначе присвоить текущему режиму разный номер в зависимости от температуры(т.е.
	выставить режим).Реализация метода в классе обогревателя : если задана температура
	выше 45 градусов, то выдать сообщение и выключиться, иначе присвоить текущему
	режиму разный номер в зависимости от температуры.В main() создать 2 кондиционера
	и 1 обогреватель, продемонстрировать полиморфизм control().
	*/
	Exercise2();

	return 0;
}