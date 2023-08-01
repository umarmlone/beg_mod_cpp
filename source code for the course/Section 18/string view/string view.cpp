#include <iostream>
#include <string_view>
#pragma region Example 1
void PrettyPrint(std::string_view message, char ch) {
	for(int x = 0 ; x < message.length() ; ++x) {
		std::cout << ch ;
	}
	std::cout <<'\n' ;
	std::cout << message << '\n' ;
}
#pragma endregion

#pragma region Example 2
enum class Title{MR, MRS, MS};
std::string & CombineName( std::string &name, std::string_view last, Title s) {
	switch (s) {
	case Title::MR:
		name.insert(0, "Mr.") ;
		break ;
	case Title::MRS:
		name.insert(0, "Mrs.") ;
		break ;
	case Title::MS:
		name.insert(0, "Ms.") ;
		break ;
	}
	return name += last ;
}
#pragma endregion

#pragma region Example 3
class Person {
	std::string m_Name;
public:
	Person(std::string name):m_Name{std::move(name)} {
		
	}
	void Print()const {
		std::cout << m_Name << std::endl; 
	}
};

Person CreatePerson(std::string_view name) {
	std::string n{name} ;
	Person p{n} ;
	return p ;
}
void WithClass() {
	using namespace std::string_literals ;
	//std::string n{} ;
	Person p{"Umar"} ;
	
	p.Print() ;
}
#pragma endregion

void BasicUsage() ;

int main() {
	//PrettyPrint("Hello world", '#') ;
	WithClass() ;
}

void BasicUsage() {
		using namespace std::string_view_literals ;
	std::string_view sv1 = "Hello world" ;

	std::string str1{"Hello"} ;
	std::string_view sv2 = str1 ;

	auto sv3 = "Using\0literals"sv ;

	std::cout << "Size:" << sv3.length() << std::endl;
	std::cout << sv3 << std::endl;

	std::cout << "data()" << sv3.data() << std::endl; 

	std::cout << sv3[0] << std::endl;
	std::cout << sv3.at(0) << std::endl ;

	auto f = sv3.find("literals") ;
	if(f != std::string::npos) {
		std::cout << "Found at index:" << f << std::endl ;
	}

	//sv3.remove_prefix(3) ;
	//std::cout << sv3 << std::endl ;

	//sv3.remove_suffix(2) ;
	//std::cout << sv3 << std::endl ;

	auto sv4 = sv1.substr(0, 5) ;

	std::cout << sv4 << std::endl; 
}