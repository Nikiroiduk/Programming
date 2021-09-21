#include "Ñonditioner.h"
#include <fstream>
Ñonditioner::Ñonditioner() {}
Ñonditioner::Ñonditioner(std::string firm,
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

void Ñonditioner::setFirm(std::string firm){
	this->firm = firm;
}

void Ñonditioner::setModel(std::string model) {
	this->model = model;
}

void Ñonditioner::setMass(double mass) {
	this->mass = mass;
}

void Ñonditioner::setTemp(double temp) {
	this->tempSum += temp;
	this->temp = temp;
}

void Ñonditioner::setState(bool state) {
	this->numOfChanges++;
	this->state = state;
}

void Ñonditioner::setReleaseYear(std::string releaseYaer) {
	this->releaseYear = releaseYaer;
}

void Ñonditioner::mode(bool state, double temp) {
	this->tempSum += temp;
	this->numOfChanges++;
}

void Ñonditioner::printState() {
	printf("\nNumber of changes: %d", numOfChanges);
	printf("\nAverage temp: %.2f", tempSum / numOfChanges);
	printf("\nCurrent mode is: %s%s", state == 0 ? "chiling" : "heating", "\n");
}

void Ñonditioner::serialize() {
	std::ofstream stream;
	stream.open("Ñonditioner.txt", std::ofstream::app);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(Ñonditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void Ñonditioner::deserialize() {
	std::ifstream stream;
	stream.open("Ñonditioner.txt");

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(Ñonditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void Ñonditioner::serialize(const std::string& filename) const {
	std::ofstream stream;
	stream.open(filename, std::ofstream::app);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(Ñonditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void Ñonditioner::deserialize(const std::string& filename) {
	std::ifstream stream;
	stream.open(filename);

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(Ñonditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}