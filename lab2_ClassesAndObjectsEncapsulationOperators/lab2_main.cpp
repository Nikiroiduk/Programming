#include "Vector.h"
#include "Fraction.h"
#include <stdio.h>
#include <iomanip> 
#include <sstream>
#include <iostream>

void Exercise1() {
	Vector* vec = new Vector(18);
	(*vec).print();
	(*vec).sort();
	(*vec).print();
	++(*vec);
	(*vec).print();
	--(*vec);
	(*vec).print();
	(*vec)--;
	(*vec).print();
	(*vec)++;
	(*vec).print();
	Matrix mat = (*vec).convertToMatrix(2, 9);
	mat.print();
	mat++;
	mat.print();
	mat--;
	mat.print();
	(++mat).print();
	(--mat).print();
}

void Exercise2() {

	//number of didgets after point
	double number = 3.1459265;
	std::stringstream ss;
	ss << std::setprecision(15) << number;
	std::string strNum = ss.str();
	size_t pos = strNum.find('.');
	if (pos != strNum.npos)
		std::cout << "Number of digits after comma: " << strNum.size() - 1 - pos << std::endl;
	else
		std::cout << "Comma not found!" << std::endl;






	Fraction x(5.0);
	Fraction y(10.0);
	printf("\n%.2f", (x + y).value);
	printf("\n%.2f", (x - y).value);
	printf("\n%.2f", (x * y).value);
	printf("\n%.2f", (x / y).value);
}

int main() {
	/*
	Написать классы Vector и Matrix для хранения и обработки одномерных и
	двумерных массивов, соответственно.Реализовать задание 2 лабораторной работы №1
	с помощью созданных классов.Все функции оформить в виде методов классов.
	В коде отразить следующее :
	- Выделение и освобождение динамической памяти производить в конструкторах и
	деструкторах классов, соответственно.
	- В классе Vector перегрузить оператор индексации[].В классе Matrix добавить
	методы T at(int i, int j) const и setAt(int i, int j, T val), которые
	позволяют получить и установить значение элемента массива с индексом[i][j], T –
	это тип элементов массива по варианту(int или double).
	- Перегрузить операторы инкремента и декремента(как префиксного, так и
	постфиксного).Смысл инкремента / декремента всего массива заключается в
	инкременте / декременте каждого элемента массива.
	*/
	//Exercise1();

	/*
	Написать класс Fraction для представления обыкновенных дробей(как отношения
	двух целых чисел x / y).Перегрузить операторы + , -, *, / для дробей.Реализовать метод
	void reduce() для сокращения дроби, а также статические методы :
	- int gcd(int n, int m)
	функция для нахождения наибольшего общего делителя чисел n и m;
	- void printAsFraction(double decimal_fraction)
	- void printAsFraction(char* decimal_fraction)
	перегруженные методы вывода десятичной дроби в виде обыкновенной
	(например, при значении decimal_fraction = 0.43 на экране должно
		вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
	Также реализовать в виде статического члена класса счетчик всех созданных на
	данный момент в программе экземпляров дробей.
	Продемонстрировать работу созданного класса.Создать несколько объектов дробей.
	Произвести операции сложения, вычитания, умножения и деления дробей.Вывести
	на экран результаты.Показать также результаты работы статических методов класса.
	*/
	Exercise2();

	return 0;
}