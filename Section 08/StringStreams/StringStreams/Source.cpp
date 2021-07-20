#include <iostream>
#include <sstream>
int main() {
	/*
	int a{5}, b{6} ;
	int sum = a + b ;
	std::stringstream ss ;
	ss << "Sum of " << a << " & " << b << " is :" << sum << std::endl;
	std::string s = ss.str() ;
	std::cout << s << std::endl;
	ss.str("") ;
	ss << sum ;
	auto ssum = std::to_string(sum) ;
	std::cout << ssum << std::endl;
	*/
	std::string data = "12 89 21" ;
	int a ;
	std::stringstream ss ;
	ss.str(data) ;
	while(ss >> a) {
		std::cout << a << std::endl; 
	}
	int x = std::stoi("54") ;
	return 0 ;
	
}