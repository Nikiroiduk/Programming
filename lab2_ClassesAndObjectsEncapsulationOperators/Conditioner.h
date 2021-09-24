#pragma once
<<<<<<< HEAD:lab2_ClassesAndObjectsEncapsulationOperators/Ð¡onditioner.h
class Ñonditioner
{
=======

#include <string>
class Conditioner    
{
private:
	double tempSum = 0;
	int numOfChanges = 0;
	std::string firm;
	std::string model;
	double mass;
	double temp;
	bool state; // 1-heating 0-chilling
	std::string releaseYear;
public:
	Conditioner();
	Conditioner(std::string firm,
				std::string model,
				double mass,
				double temp,
				bool state,
				std::string releaseYaer);
	void setFirm(std::string firm);
	void setModel(std::string model);
	void setMass(double mass);
	void setTemp(double temp);
	void setState(bool state);
	void setReleaseYear(std::string releaseYear);
	void mode(bool state, double temp);
	void printState();
	void serialize();
	void deserialize();
	void serialize(const std::string& filename) const;
	void deserialize(const std::string& filename);
>>>>>>> NewWorld:lab2_ClassesAndObjectsEncapsulationOperators/Conditioner.h
};

