//#pragma once
class Car {
private:
	float fuel;
	float speed;
	int passengers;
	static int totalCount;
public:
	Car();
	Car(float amount);
	Car(float amount, int pass);
	~Car();
	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassengers(int count);
	void Dashboard();
	static void ShowCount();
};