#include "HouseholdDevice.h"
#include "IControllable.h"
#pragma once
class Conditioner : public HouseholdDevice, public IControllable
{
private:
	void setMode(int temperature) override;
public:
	Conditioner();
	Conditioner(string firm,
		string model,
		int temp,
		double mass,
		string releaseYaer);
	void control(int temperature) override;
};

