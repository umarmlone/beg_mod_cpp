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
	auto f = [](int x) {
		return Subtract(x,5) ;
	} ;
	std::cout << f(8) << '\n' ; //Subtract(2,3) ;

	//auto gt = std::bind(GreaterThan{}, _2, _1) ;
	auto gt = [](int x,int y) {
		return GreaterThan{}(y, x) ;
	} ;
	std::cout << gt(6,2) << '\n' ; //operator()(2,6)

	//auto acc = std::bind(Accumulate,_1, _2, 0) ;
	auto acc = [](int x,int y) {
		return Accumulate(x,y, 0) ;
	} ;
	std::cout << Operation(8,5, acc) << '\n';

}