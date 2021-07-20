#include <iostream>
#include <string>

union Test {
	int x ;
	char ch ;
	double d ;
	Test(): ch{'a'} {
		std::cout << __FUNCSIG__ << std::endl; 
	}
	~Test() {
		std::cout << __FUNCSIG__ << std::endl; 
	}
};
struct A {
	A() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~A() {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(A&& other) noexcept{
		std::cout << __FUNCSIG__ << std::endl;
	}

	A& operator=(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}

	A& operator=(A&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}
};
struct B {

	B() {
		std::cout << __FUNCSIG__ << std::endl;

	}
	~B() {
		std::cout << __FUNCSIG__ << std::endl;

	}

	B(const B& other) {
		std::cout << __FUNCSIG__ << std::endl ;
	}

	B(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl ;
	}

	B& operator=(const B& other) {
		std::cout << __FUNCSIG__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}

	B& operator=(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}
	virtual void Foo(){}
	
};

union UDT {
	A a ;
	B b ;
	std::string s ;
	UDT() {
		
	}
	~UDT() {
		
	}
};
int main() {
	using namespace std::string_literals ;
	UDT udt ;
	//new(&udt.s) std::string{"Hello world"} ;

	new (&udt.a) A{} ;
	udt.a.~A() ;
	
	/*std::cout << sizeof(Test) << std::endl; 
	Test t ;
	std::cout << t.ch << std::endl;

	t.x = 1000 ;

	std::cout << t.ch << std::endl; */
	
}