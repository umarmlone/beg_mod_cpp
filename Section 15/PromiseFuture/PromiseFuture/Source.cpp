#include <future>
#include <iostream>
#include <thread>

int Operation(std::promise<int> & data) {
	using namespace std::chrono_literals;
	auto f = data.get_future() ;
	try {
		std::cout << "[Task] Waiting for count\n";
		auto count = f.get();
		std::cout << "[Task] Count acquired.\n";
		int sum{};
		for (int i = 0; i < count; ++i) {
			sum += i;
			std::cout << '.';
			std::this_thread::sleep_for(300ms);//std::chrono::seconds(1) 
		}
		return sum;
	}catch(std::exception &ex) {
		std::cout << "[Task] Exception:" << ex.what() << std::endl; 
	}
}
int main() {
	using namespace std::chrono_literals ;
	std::promise<int> data ;
	std::future<int> result = std::async(std::launch::async, Operation, std::ref(data));
	std::this_thread::sleep_for(1s) ;
	std::cout << "[main] Setting the data in promise\n";
	try {
		throw std::runtime_error{"Data not available"} ;
		data.set_value(10);
		if (result.valid()) {
			auto sum = result.get();
			std::cout << sum << std::endl;
		}
	}catch(std::exception &ex) {
		data.set_exception(std::make_exception_ptr(ex)) ;
	}
	
}