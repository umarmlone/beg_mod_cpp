#include <iostream>
#include "car.h"
static int car::totalcars = 0;
car::car(float fuelam):car(fuelam , 1)
{
    std::cout << "the old constructor with default value of passengers" << std::endl;
}

car::car(float fuelamm, int pass)
{
    
    std::cout << "delegating constructor" << std::endl;
    fuel = fuelamm;
    passengers = pass;
    speed = 0;
    totalcars++;

}

void car::add_fuel(float fuel_value)
{
    fuel += fuel_value ;
}

void car::accelerate()
{
    fuel -= 0.5f;
    speed++;
}

void car::brake()
{
    std::cout<< "the car is stopping"<<std::endl;
    speed = 0 ;
}

void car::add_passengers(int pass_num)
{
    if(passengers >=4)
    {
        std::cout<<"can't add more passengers"<<std::endl;
    }
    else
        passengers += pass_num ;
    
}
void car::Dashboard()
{
    std::cout<<"the fuel amount is : "<< fuel <<"\n the passengers number is : "<<passengers <<"\n the speed is : "<< speed <<std::endl;
    std::cout << "the number of cars created are : " << totalcars << std::endl;
}

void car::PrintObjects()
{
    std::cout << "the number of cars inside the code are : " << totalcars<<std::endl;
}

car::~car()
{
    std::cout<<"destructing the object"<<std::endl;
    passengers = 0;
    speed = 0;
    totalcars--;
}