#pragma once
class IControllable {
protected:
	virtual void setMode(int temperature) = 0;
public:
	virtual void control(int temperature) = 0;
};