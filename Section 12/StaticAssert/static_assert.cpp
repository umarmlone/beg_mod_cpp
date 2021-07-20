#include <iostream>
#include <type_traits>
template<typename T>
T Divide(T a, T b){
	static_assert(std::is_floating_point<T>::value, "Only floating point type supported") ;
	if(std::is_floating_point<T>::value == false){
		std::cout << "Use floating point types only\n" ;
		return 0 ;
	}
	return a/b ;
}
int main(){
	std::cout 
	<< std::boolalpha
	<< "Is integer?" << std::is_integral<int>::value << std::endl;
	
	std::cout << Divide(5.1, 7.3) << std::endl ;
}