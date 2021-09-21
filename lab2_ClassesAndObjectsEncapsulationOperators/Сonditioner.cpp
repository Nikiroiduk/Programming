#include "�onditioner.h"
#include <fstream>
�onditioner::�onditioner() {}
�onditioner::�onditioner(std::string firm,
						 std::string model,
						 double mass,
						 double temp, 
						 bool state,
						 std::string releaseYaer) {
	this->firm = firm;
	this->model = model;
	this->mass = mass;
	this->temp = temp;
	this->state = state;
	this->releaseYear = releaseYaer;
	this->tempSum += temp;
	this->numOfChanges++;
}

void �onditioner::setFirm(std::string firm){
	this->firm = firm;
}

void �onditioner::setModel(std::string model) {
	this->model = model;
}

void �onditioner::setMass(double mass) {
	this->mass = mass;
}

void �onditioner::setTemp(double temp) {
	this->tempSum += temp;
	this->temp = temp;
}

void �onditioner::setState(bool state) {
	this->numOfChanges++;
	this->state = state;
}

void �onditioner::setReleaseYear(std::string releaseYaer) {
	this->releaseYear = releaseYaer;
}

void �onditioner::mode(bool state, double temp) {
	this->tempSum += temp;
	this->numOfChanges++;
}

void �onditioner::printState() {
	printf("\nNumber of changes: %d", numOfChanges);
	printf("\nAverage temp: %.2f", tempSum / numOfChanges);
	printf("\nCurrent mode is: %s%s", state == 0 ? "chiling" : "heating", "\n");
}

void �onditioner::serialize() {
	std::ofstream stream;
	stream.open("�onditioner.txt", std::ofstream::app);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(�onditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void �onditioner::deserialize() {
	std::ifstream stream;
	stream.open("�onditioner.txt");

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(�onditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void �onditioner::serialize(const std::string& filename) const {
	std::ofstream stream;
	stream.open(filename, std::ofstream::app);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(�onditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void �onditioner::deserialize(const std::string& filename) {
	std::ifstream stream;
	stream.open(filename);

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(�onditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}