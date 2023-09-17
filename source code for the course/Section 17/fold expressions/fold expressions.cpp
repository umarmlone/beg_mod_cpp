#include <iostream>

auto Sum() {
	return 0 ;
}
template<typename T, typename ...Args>
auto Sum(T a, Args...args) {
	return a + Sum(args...) ;
}
/*
 * Sum(1,2,3,4,5) ;
 * return 1 + Sum(2,3,4,5) ;
 * return 2 + Sum(3,4,5) ;
 * return 3 + Sum(4,5) ;
 * return 4 + Sum(5) ;
 * return 5 + Sum() ;
 * return 5 + 0 ;
 *
 *  1 + (2 + (3 + (4 + (5 + 0))))
 *  1 + (2 + (3 + (4 + 5)))
 *  1 + (2 + (3 + 9))
 *  1 + (2 + 12)
 *  1 + 14
 *  15
 * 
 */

template<typename...Args>
auto Sum2(Args...args) {
	//return (args + ...) ;   //Unary right fold
	return (... + args) ;   //Unary left fold
}
template<typename...Args>
auto Sum3(Args...args) {
	//return (0 + ... + args) ;   //Binary left fold
	return (args + ... + 0) ;   //Binary right fold
}
/*
 * Unary Right Fold
 * Sum2(1,2,3,4,5)
 * (1 +(2 + (3 + (4 + 5))))
 *
 * Unary Left Fold
 * ((((1 + 2) + 3) + 4) + 5)
 */


/*
 * Binary Right fold
 * 1 + (2 + (3 + (4 + (5 + 0))))
 *
 * Binary Left Fold
 * (((((0+1)+2) + 3) + 4) + 5)
 */

/*
 + - * / % ^ & | = < > << >> += -
= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*

&&          - true
||          - false
,           - void()
Others      - ill-formed
 */

template<typename...Args>
bool AnyOf(Args...args) {
	return (... || (args % 2 == 0)) ;
}
template<typename...Args>
bool AllOf(Args...args) {
	return (... && (args % 2 == 0)) ;
}

template<typename...Args, typename Predicate>
bool AnyOf2(Predicate p, Args...args) {
	return (... || p(args)) ;
}
int main() {
	auto result = Sum3(1,2,3,4,5) ;
	//std::cout << result << std::endl;

	std::cout << std::boolalpha ;
	std::cout << "Any even?" << AnyOf(10,3,5) << std::endl; 
	std::cout << "All even?" << AllOf(10,30,52) << std::endl;

    std::cout << "Any even?" << AnyOf2([](int x){return x % 2 == 0;},10,3,5) << std::endl; 

}
