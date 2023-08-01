#include <iostream>
#include <memory>
#include <vector>
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};
class Test {
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	Test() { 
		std::cout << "Test():Acquire resources" << std::endl;
		pA.reset(new A);

		/*pA = new A;
		pInt = new int;
		pStr = new char[1000];
		pArr = new int[50000];*/
	}
	~Test() {  
		std::cout << "~Test():Release resources" << std::endl; 
		throw std::runtime_error("Failed to initialize");
		/*delete pA;
		delete pInt;
		delete[]pStr;
		delete[] pArr;*/
	}
};

int main() {
	try {
		Test t;
		throw std::runtime_error{ "Exception" };
	}
	catch (std::runtime_error &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}