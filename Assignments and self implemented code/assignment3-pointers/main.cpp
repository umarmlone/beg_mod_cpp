#include <iostream>
#include "assignment3_pointers.h"


int main()
{
	int x{ 6 };
	int result{ 1 };
	/*
	std::cout << &x << '\n' << &y << '\n' << x << '\n' << y <<  std::endl;
	Swap(&x, &y);
	std::cout << &x <<'\n'<<&y << '\n'<< x <<'\n' << y << std::endl;
	*/
	Factorial(&x, &result);
	std::cout << result << std::endl;
	return 0;
}
