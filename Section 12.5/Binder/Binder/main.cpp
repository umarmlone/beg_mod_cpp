#include <iostream>
#include <functional>

int Subtract(int x, int y) {
	return x - y;
}
void Print(const char *p) {
	std::cout << p << '\n' ;
}
struct GreaterThan {
	bool operator()(int x,int y)const {
		return x > y ;
	}
};
int Operation(int x,int y, std::function<int(int,int)> callback) {
	return callback(x,y) ;
}
int Accumulate(int x,int y, int z) {
	return x + y + z ;
}
int main() {
	using namespace std::placeholders ;
	//std::function<int(int,int)> f = std::bind(Subtract,std::placeholders::_2,std::placeholders::_1) ;
	//auto f = std::bind(Subtract,_1, 5) ;
	auto f = [](auto && x) {
		return Subtract(std::forward<decltype(x)>(x),5) ;
	} ;
	std::cout << f(8) << '\n' ; //Subtract(2,3) ;

	//auto gt = std::bind(GreaterThan{}, _2, _1) ;
	//C++20 template type parameters in lambda
	auto gt = []<typename T>(T&& x,T&& y) {
		return GreaterThan{}(std::forward<T>(y), std::forward<T>(x)) ;
	} ;
	std::cout << gt(6,2) << '\n' ; //operator()(2,6)

	//auto acc = std::bind(Accumulate,_1, _2, 0) ;
	//C++20 template type parameters in lambda
	auto acc = []<typename T>(T&& x,T&& y) {
		return Accumulate(std::forward<T>(x),std::forward<T>(y), 0) ;
	} ;
	std::cout << Operation(8,5, acc) << '\n';

}