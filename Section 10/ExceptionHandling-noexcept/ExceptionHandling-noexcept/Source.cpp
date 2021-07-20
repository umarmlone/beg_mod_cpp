#include <iostream>
void Test(int x)noexcept(false) {
	std::cout << x << std::endl;
	//throw x;
}
int Sum(int x, int y)noexcept(noexcept(Test(x))) {
	Test(x);
	return x + y;
}
class A {
public:
	//Destructors are implicitly noexcept(true) in C++11
	~A() {
		throw 3; 
	}
};
int main() {
	A a;
	//boolalpha manipulator prints 0 & 1 as false & true
	std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;
	try {
		Sum(3, 5);
		//Other statements
	}
	catch (int x) {
		std::cout << x << std::endl ;
	}
}