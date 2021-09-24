<<<<<<< HEAD
#include "Ñonditioner.h"
=======
#include "Conditioner.h"
#include <fstream>
Conditioner::Conditioner() {}
Conditioner::Conditioner(std::string firm,
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

void Conditioner::setFirm(std::string firm){
	this->firm = firm;
}

void Conditioner::setModel(std::string model) {
	this->model = model;
}

void Conditioner::setMass(double mass) {
	this->mass = mass;
}

void Conditioner::setTemp(double temp) {
	this->tempSum += temp;
	this->temp = temp;
}

void Conditioner::setState(bool state) {
	this->numOfChanges++;
	this->state = state;
}

void Conditioner::setReleaseYear(std::string releaseYaer) {
	this->releaseYear = releaseYaer;
}

void Conditioner::mode(bool state, double temp) {
	this->tempSum += temp;
	this->numOfChanges++;
}

void Conditioner::printState() {
	printf("\nNumber of changes: %d", numOfChanges);
	printf("\nAverage temp: %.2f", tempSum / numOfChanges);
	printf("\nCurrent mode is: %s%s", state == 0 ? "chiling" : "heating", "\n");
}

void Conditioner::serialize() {
	std::ofstream stream;
	stream.open("Ñonditioner.txt", std::ofstream::app);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(Conditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void Conditioner::deserialize() {
	std::ifstream stream;
	stream.open("Ñonditioner.txt");

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(Conditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void Conditioner::serialize(const std::string& filename) const {
	std::ofstream stream;
	stream.open(filename, std::ofstream::app);

	if (stream.is_open()) {
		printf("\nFile is open for writing");
		stream.write((char*)this, sizeof(Conditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}

void Conditioner::deserialize(const std::string& filename) {
	std::ifstream stream;
	stream.open(filename);

	if (stream.is_open()) {
		printf("\nFile is open for reading");
		stream.read((char*)this, sizeof(Conditioner));
	}
	else {
		printf("\nError while open file");
	}

	stream.close();
}
>>>>>>> NewWorld
