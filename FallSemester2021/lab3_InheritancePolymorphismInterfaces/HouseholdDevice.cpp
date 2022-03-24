#include "HouseholdDevice.h"
#include <fstream>
using std::string;
HouseholdDevice::HouseholdDevice() {}
HouseholdDevice::HouseholdDevice(string firm, string model, int temp, double mass, string releaseYaer) {
	this->firm = firm;
	this->model = model;
	this->mass = mass;
	this->releaseYear = releaseYaer;
	this->temp = temp;
	tempSum += temp;
	++numOfChanges;
}

void HouseholdDevice::setFirm(string firm) {
	this->firm = firm;
}

void HouseholdDevice::setModel(string model) {
	this->model = model;
}

void HouseholdDevice::setMass(double mass) {
	this->mass = mass;
}

void HouseholdDevice::setTemp(int temp) {
	this->temp = temp;
	tempSum += temp;
	++numOfChanges;
}

void HouseholdDevice::setReleaseYear(string releaseYaer) {
	this->releaseYear = releaseYaer;
}

void HouseholdDevice::printState() {
	printf("\nNumber of changes: %d", numOfChanges);
	printf("\nAverage temp: %.2f", (double)(tempSum / numOfChanges));
	printf("\nStatus: %s%s", state == true ? "enabled" : "disabled", "\n");
}

void HouseholdDevice::serialize() {
	std::string fileName = firm + model + ".txt";
	std::ofstream stream;
	stream.open(fileName);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(HouseholdDevice));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void HouseholdDevice::deserialize() {
	std::string fileName = firm + model + ".txt";
	std::ifstream stream;
	stream.open(fileName);

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(HouseholdDevice));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void HouseholdDevice::serialize(const string& filename) const {
	std::ofstream stream;
	stream.open(filename);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(HouseholdDevice));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void HouseholdDevice::deserialize(const string& filename) {

	std::ifstream stream;
	stream.open(filename);

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(HouseholdDevice));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

HouseholdDevice::~HouseholdDevice() {}