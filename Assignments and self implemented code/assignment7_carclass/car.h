#pragma once
class car
{
private:

    float fuel;
    int speed;
    int passengers;


public:
    car(float fuelam);
    car(float fuelamm, int pass);
    ~car();
    void add_passengers(int pass_num);
    void add_fuel(float fuel_value);
    void brake();
    void accelerate();
    void Dashboard();
    static int totalcars;
    static void PrintObjects();
};