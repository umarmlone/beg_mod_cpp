#define _CRT_SECURE_NO_WARNINGS //Suppress compiler errors for usage of non-secure C functions
#include <iostream>
#include <cstring>
#include <string>

const char * Combine(const char *pFirst, const char *pLast) {
	char *fullname = new char[strlen(pFirst) + strlen(pLast) + 1] ;
	strcpy(fullname, pFirst) ;
	strcat(fullname, pLast) ;
	return fullname ;
}

std::string Combine(const std::string &first, const std::string &last) {
	std::string fullname = first + last ;
	return fullname ;
}
int main() {
	/*
	char first[10] ;
	char last[10] ;
	std::cin.getline(first, 10) ;
	std::cin.getline(last, 10) ;

	const char *pFullName = Combine(first, last) ;
	//Insert into database

	std::cout << pFullName << std::endl ;
	delete[] pFullName ;
	*/

	std::string first ;
	std::string last ;

	std::getline(std::cin, first) ;
	std::getline(std::cin, last) ;

	//std::string fullname = first + last ;
	std::string fullname = Combine(first, last) ;
	printf("%s", fullname.c_str()) ;

	//Insert into database

	std::cout << fullname << std::endl; 

	std::string first1 = "Umar" ;
	std::string last1("Lone") ;

	std::string name{"Umar Lone"} ;
	using namespace std::string_literals ;
	auto n2 = "Umar Lone"s ;

	unsigned int value = 100u ;
	return 0 ;
}

void UsingStdString() {
		//Initialize & assign
	std::string s = "Hello" ;
	s = "Hello" ;
	//Access
	s[0] = 'W' ;
	char  ch = s[0] ;

	std::cout << s << std::endl;
	std::cin >> s;

	std::getline(std::cin, s) ;
	//Size
	s.length() ;

	//Insert & concatenate
	std::string s1{"Hello"}, s2{"World"} ;
	s = s1 + s2 ;

	s+=s1 ;

	s.insert(6, "World") ;

	//Comparison
	if(s1 == s2) {
		std::cout << "Same\n"	 ;
	}

	//Removal
	s.erase( );
	s.erase(0, 5) ;
	s.clear() ;

	//Search
	auto pos = s.find("World", 0) ;
	if(pos != std::string::npos) {
		//Found
	}
}