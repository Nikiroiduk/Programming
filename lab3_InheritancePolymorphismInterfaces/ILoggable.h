#pragma once
#include <string>
class ILoggable
{
public:
	virtual void logToScreen();
	virtual void logToFile(const std::string& filename);
};