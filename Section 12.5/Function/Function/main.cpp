#include <iostream>
#include <functional>
int Square(int x) {
	return x * x;
}
int Add(int x, int y) {
	return x + y;
}
int Subtract(int x, int y) {
	return x - y;
}
struct Max {
	int operator()(int x,int y)const {
		return x > y ? x : y ;
	}
};
int Operation(int x,int y, std::function<int(int,int)> callback) {
	return callback(x,y) ;
}
int main() {
	try {
		/*std::function<int(int)> f1  ;
		if(f1) {
			std::cout << f1(3) << std::endl ;
		}else {
			std::cout << "No target to invoke!\n" ;
		}
		Max m{} ;
		std::function<int(int,int)> f2 = m ;
		std::cout << f2(3,5) << '\n' ;

		std::function<bool(int)> f3 = [](int x){return x % 2 == 0;} ;
		std::cout << "IsEven?" << f3(4) << '\n' ;*/
		std::function<int(int,int)> f1 = Add ;
		std::cout << Operation(3,5, f1) << '\n' ;
		f1 = Subtract ;
		std::cout << Operation(3,5, f1) << '\n' ;
		std::cout << Operation(3,5, [](int x,int y){return x*y;}) << '\n' ;

	}
	catch (const std::exception& ex) {
		std::cout << "Exception -> " << ex.what() << '\n';
	}
}