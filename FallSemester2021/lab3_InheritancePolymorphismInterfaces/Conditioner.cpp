#include "Conditioner.h"

Conditioner::Conditioner() : HouseholdDevice() {}
Conditioner::Conditioner(string firm, string model, int temp, double mass, string releaseYear) :
	HouseholdDevice(firm, model, temp, mass, releaseYear) {}

void Conditioner::control(int temperature) {
	if (temperature < 10) {
		printf("\nToo low temperature.\nShutting down.\n");
		state = false;
	}
	else if (temperature < 45){
		setMode(temperature);
	}
	else {
		printf("\nTemperature is too high.\nShutting down.\n");
		state = false;
	}
}

void Conditioner::setMode(int temperature) {
	if (temp > temperature) {
		state = true;
	}
	else {
		state = false;
	}
	this->temp = temperature;
	this->tempSum += temp;
	this->numOfChanges++;
}