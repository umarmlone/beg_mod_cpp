#include <iostream>
#define DELETE_COPY_MOVE
class Number {
public:
	Number(int value) {
		std::cout << "Parameterized ctor\n" ;
	}
#ifdef DELETE_COPY_MOVE
	Number(const Number &) = delete ;
	Number(Number &&) = delete ;
#else
	Number(const Number &) {
		std::cout << "Copy ctor\n" ;
	}
	Number(Number &&){
		std::cout << "Move ctor\n" ;
	}
#endif
};

void Foo(Number n) {
	
} 

Number Create() {
	//Number n{0} ;
	//return n ;

	return Number{0} ;
}
template<typename T, typename...Args>
T Create(Args&&...args) {
	return T{args...} ;
}
int main() {
	//Number n1 = Number{3} ;
	//Foo(Number{3}) ;

	//auto n2 = Create() ;

	auto n3 = Create<Number>(0) ;
}

