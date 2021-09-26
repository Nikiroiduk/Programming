#include "ILoggable.h"

#pragma once
class ExpressionEvaluator : public ILoggable
{
public:
	virtual double calculate();
};

