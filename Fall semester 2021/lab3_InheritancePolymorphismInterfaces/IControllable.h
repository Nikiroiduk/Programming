#pragma once
class IControllable {
protected:
	virtual void setMode(int temperature) = 0;
	virtual ~IControllable() {}
public:
	virtual void control(int temperature) = 0;
};