#include <iostream>
#include <map>

struct Person {
	std::string m_Name ;
	int m_Age ;
	Person() = default ;
	Person(const std::string &name, int age):m_Name{name}, m_Age{age}{}
};

struct S1 {
	int arr1[8] ;
	char ch1[256] ;
};

int main() {
	S1 s ;
	auto [s1, s2] = s ;
	
	Person p{"Ayaan", 14} ;
	/*auto name = p.m_Name ;
	auto age = p.m_Age ;*/

	const auto &[name, age] = p ;
	//age = 10 ;

	std::cout << p.m_Age << std::endl;

	std::pair<int,int> p1{3,5} ;
	auto [key, value] = p ;

	std::map<int, std::string> errorInfo{ {1, "Not available"}, {2, "Port is in use"}} ;

	for(auto err : errorInfo) {
		std::cout << err.first << ":" << err.second << std::endl; 
	}

	for(auto [key, value] : errorInfo) {
		std::cout << key << ":" << value << std::endl; 
	}

	int arr[] = {1,2,3} ;
	auto [a, b, c] = arr ;

	auto arr2 = arr ;
	

}