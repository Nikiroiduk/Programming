#include "ILoggable.h"
#pragma once
class ExpressionEvaluator : public ILoggable
{
protected:
	int numOfOperands = 0;
	double* operands;

	// this thing is used to output arithmetic symbols ¯\_(ツ)_/¯
	char symbol = '0';
private:
	virtual void initializeZeros();
public:
	virtual void sort();
	virtual void swap(size_t i, size_t j);
	virtual ~ExpressionEvaluator();
	ExpressionEvaluator(int numOfOperands);
	ExpressionEvaluator();
	virtual void setOperand(size_t pos, double value);
	virtual void setOperands(double ops[], size_t n);
	virtual double calculate() = 0;

	// implement ILoggable
	virtual void logToScreen() const override;
	virtual void logToFile(const std::string& filename) const override;
};

