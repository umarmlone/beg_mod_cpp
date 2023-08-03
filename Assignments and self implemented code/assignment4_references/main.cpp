#include "assignment4_references.h"
#include <iostream>

int main()
{
	int result = 0;
	int& res_ref = result;
	int x{ 4 }, y{ 3 };
	std::cout << "before swap '\n'";
	std::cout << "x = " << x << " y = " << y << std::endl;
	int& refx{ x }, & refy{ y };
	Swap(refx, refy);
	std::cout << "after swap '\n'";
	std::cout << "x = " << x << " y = " << y << std::endl;

	Add(5, 4, res_ref);
	Factorial(8, res_ref);
	std::cout << "result is : " << res_ref << std::endl;
}