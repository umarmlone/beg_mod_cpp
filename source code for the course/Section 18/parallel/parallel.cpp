#include <chrono>
#include <iostream>
#include <random>
#include <string_view>
#include <vector>
#include <execution>
class Timer {
	std::chrono::steady_clock::time_point m_start ;
public:
	Timer():m_start{std::chrono::steady_clock::now()} {
		
	}
	void ShowResult(std::string_view message = "") {
		auto end = std::chrono::steady_clock::now() ;
		auto difference = end - m_start ;
		std::cout << message
			<< ':'
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(difference).count()
			<< '\n' ;
	}
};
constexpr unsigned VEC_SIZE{100} ;
std::vector<long> CreateVector() {
	std::vector<long> vec ;
	vec.reserve(VEC_SIZE) ;
	std::default_random_engine engine{std::random_device{}()} ;
	std::uniform_int_distribution<long> dist{0, VEC_SIZE} ;
	for(unsigned i = 0 ; i < VEC_SIZE ; ++i) {
		vec.push_back(dist(engine)) ;
	}
	return vec ;
}
int main() {
	auto dataset = CreateVector() ;
	Timer t ;
	std::sort(dataset.begin(), dataset.end()) ;
	//std::sort(std::execution::par, dataset.begin(), dataset.end()) ;
	//
	//auto result = std::accumulate(dataset.begin(), dataset.end(),0L) ;
	//auto result = std::reduce(dataset.begin(), dataset.end(),0L) ;
	
	t.ShowResult("Accumulate time") ;

}

