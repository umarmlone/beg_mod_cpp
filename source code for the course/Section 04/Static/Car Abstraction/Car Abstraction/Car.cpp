#include "Car.h"
#include <iostream>
int Car::totalCount = 0;
Car::Car():Car(0) {
	std::cout << "Car()" << std::endl;
}

Car::Car(float amount):Car(amount, 0) {
	std::cout << "Car(float)" << std::endl;

}

Car::Car(float amount, int pass) {
	std::cout << "Car(float, int)" << std::endl;
	++totalCount;
	fuel = amount;
	speed = 0;
	passengers = pass;
}

Car::~Car() {
	--totalCount;
	std::cout << "~Car()" << std::endl; 
}

void Car::FillFuel(float amount) {
	fuel = amount;
}

void Car::Accelerate() {
	this->speed++;
	this->fuel -= 0.5f;
}

void Car::Brake() {
	speed = 0;
}

void Car::AddPassengers(int count) {
	passengers = count;
}

void Car::Dashboard()const {
	std::cout << "Fuel:" << fuel << std::endl;
	std::cout << "Speed:" << speed << std::endl;
	std::cout << "Passengers:" << passengers << std::endl;
}

void Car::ShowCount() {
	std::cout << "Total cars : " << totalCount << std::endl;
}
