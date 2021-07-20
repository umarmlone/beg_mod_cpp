#include <iostream>
//Possible implementation of a lambda expression as a function object
template<typename T>
struct Unnamed {
	T operator()(T x, T y)const {
		return x + y;
	}
};
int main() {
	//Compiler automatically creates a function object
	auto fn = []() {
		std::cout << "Welcome to Lambda expressions" << std::endl ;
	};
	fn();
	std::cout << typeid(fn).name() << std::endl;
	//Generic/polymorphic lambda
	//							  <optional specifiers>
	auto sum = [](auto x, auto y)/*mutable*/ /*noexcept*/(false){
		return x + y;			//	^^^^		^^^^
	};
	Unnamed<int> n;
	std::cout << "Sum is:" << sum(5.5f, 2.2f) << std::endl;
	return 0;
}