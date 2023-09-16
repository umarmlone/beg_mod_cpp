
#include "car.h"
#include <iostream>



int main()
{
    std::cout << "Hello World!\n";
    car car1(40, 3);
    car Car2(20);
    car::PrintObjects();
    Car2.~car();
    car::PrintObjects();
    return 0;
}

