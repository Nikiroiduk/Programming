#include "HouseholdDevice.h"
#include "IControllable.h"
#pragma once
class Heater : public HouseholdDevice, public IControllable
{
private:
	void setMode(int temperature) override;
public:
	Heater();
	Heater(string firm,
		string model,
		int temp,
		double mass,
		string releaseYaer);
	void control(int temperature) override;
};

