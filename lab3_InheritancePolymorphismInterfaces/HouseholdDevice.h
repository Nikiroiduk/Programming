#pragma once
#include <string>

using std::string;
class HouseholdDevice
{
protected:
	int tempSum = 0;
	int numOfChanges = 0;
	string firm = "Undefined";
	string model = "Undefined";
	double mass = 0;
	int temp = 0;
	bool state = false; // 1-enable 0-disable
	string releaseYear = "Undefined";
public:
	HouseholdDevice();
	HouseholdDevice(string firm,
		string model,
		int temp,
		double mass,
		string releaseYaer);
	virtual void setFirm(string firm);
	virtual void setModel(string model);
	virtual void setTemp(int temp);
	virtual void setMass(double mass);
	virtual void setReleaseYear(string releaseYear);
	virtual void printState();
	virtual void serialize();
	virtual void deserialize();
	virtual void serialize(const string& filename) const;
	virtual void deserialize(const string& filename);
	virtual ~HouseholdDevice();
};
