#include "Heater.h"

Heater::Heater() : HouseholdDevice() {}
Heater::Heater(string firm, string model, int temp, double mass, string releaseYear) :
	HouseholdDevice(firm, model, temp, mass, releaseYear) {}

void Heater::control(int temperature) {
	if (temperature > 45) {
		printf("\nToo high temperature.\nShutting down.\n");
		state = false;
	}
	else if (temperature < 45) {
		setMode(temperature);
	}
	else {
		printf("\nTemperature is too low.\nShutting down.\n");
		state = false;
	}
}

void Heater::setMode(int temperature) {
	if (temp < temperature) {
		state = true;
	}
	else {
		state = false;
	}
	this->temp = temperature;
	this->tempSum += temp;
	this->numOfChanges++;
}