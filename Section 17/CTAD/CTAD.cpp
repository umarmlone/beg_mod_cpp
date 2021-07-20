#include <iostream>
#include <mutex>
#include <vector>

template<typename T>
class Data {
public:
	Data(const T &t) {
		
	}
};
Data(const char *) -> Data<std::string> ;
Data(int)->Data<long> ;
int main() {

	Data d1{5} ;
	Data d2{8.2f} ;

	Data d3 = d1 ;
	auto d4 = new Data{"Hello"} ;

	Data d5{"Hello"} ;

	Data d6{5} ;
	
	std::pair<int,int> p1{2,5} ;
	auto p2 = std::make_pair(2,5) ;

	std::pair p3{2,5} ;
	std::vector v1{1,2,3,4} ;

	std::mutex m ;
	std::lock_guard lck{m} ;
	
}
