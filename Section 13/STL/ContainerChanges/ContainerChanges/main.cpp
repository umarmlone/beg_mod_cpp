#include <deque>

#include "Integer.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <set>

void Emplace() {
	std::vector<Integer> vInt ;
	Integer val{5} ;
	//vInt.push_back(val) ;
	vInt.emplace_back(val) ;

	std::vector<std::pair<int, std::string>> data ;
	data.push_back(std::pair<int, std::string>{100, "C++"}) ;

	data.emplace_back(100, "C++") ;
}
void Shrink() {
	std::vector<int> vInt ;
	for(size_t i = 0 ; i < 100 ; ++i) {
		vInt.emplace_back(i) ;
	}
	std::cout << "Size:" << vInt.size() << '\n' ;
	std::cout << "Capacity:" << vInt.capacity() << '\n' ;
	vInt.erase(vInt.begin(), vInt.end()-10) ;
	std::cout <<"After erase & shrink_to_fit\n" ;
	vInt.shrink_to_fit() ;
	std::cout << "Size:" << vInt.size() << '\n' ;
	std::cout << "Capacity:" << vInt.capacity() << '\n' ;
}
void VectorFunctions() {
	std::ifstream input{"main.cpp"} ;
	if(!input) {
		std::cout << "Could not open file\n" ;
		return ;
	}
	auto size = std::filesystem::file_size("main.cpp") ;
	//std::vector<char> buffer ;
	std::string buffer ;
	buffer.resize(size) ;
	//char * buff = new char[size]{};
	input.read(buffer.data(), size) ;
	std::cout << buffer.data() << '\n' ;
	//delete []buff ;
}

template<typename Container>
void Print(const Container &cont, const char *msg="") {
	std::cout << msg << '\n' ;
	for(auto a : cont) {
		std::cout << a << '\n' ;
	}
}
void Erase() {
	std::vector<int> vInt{1,2,3,4,2} ;
	std::list<int> lstInt{1,2,3,4,2} ;
	std::deque<int> deqInt{1,2,3,4,2} ;

	std::erase(vInt,2) ;
	std::erase(lstInt,2) ;
	std::erase(deqInt,2) ;

	Print(vInt, "vector") ;
	Print(lstInt, "list") ;
	Print(deqInt, "deque") ;
}

int main() {
	//std::set<int> data{1,2,6,3} ;
	//data.emplace_hint(data.begin(),0) ;
	//auto it = data.find(6) ;
	//if(it != data.end()) {
	//	std::cout << "Found\n" ;
	//}
	//auto found = data.contains(6) ;
	//if(found){
	//	std::cout << "Found\n" ;
	//}

	std::set<std::string> names{"Omar", "Ayaan", "Raihaan"} ;
	auto it = names.find("Omar") ;
	auto name = *it ;
	name[0] = 'U' ;
	names.erase(it) ;
	names.insert(name) ;

	auto node = names.extract(it) ;
	node.value()[0] = 'U' ;
	names.insert(std::move(node)) ;
	
	return 0;
}
