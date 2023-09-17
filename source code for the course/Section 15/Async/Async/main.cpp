#include <future>
#include <iostream>
#include <thread>

int Operation(int count) {
	using namespace std::chrono_literals;
	int sum{};
	for (int i = 0; i < count; ++i) {
		sum += i;
		std::cout << '.';
		std::this_thread::sleep_for(300ms);//std::chrono::seconds(1) 
	}
	return sum;
}
int main() {
	using namespace std::chrono_literals ;
	std::future<int> result = std::async(std::launch::async, Operation, 10);
	std::this_thread::sleep_for(1s) ;
	std::cout << "main() thread continues execution...\n";
	if (result.valid()) {
		auto timepoint = std::chrono::system_clock::now() ;
		timepoint += 1s ; 
		auto status = result.wait_until(timepoint) ;
		//auto status = result.wait_for(4s) ;
		switch(status) {
		case std::future_status::deferred:
			std::cout << "Task is synchronous\n" ;
			break ;
		case std::future_status::ready:
			std::cout << "Result is ready\n" ;
			break ;
		case std::future_status::timeout:
			std::cout << "Task is still running\n" ;
			break ;
		}
		//result.wait() ;
		//Operation(10) ;
		auto sum = result.get();
		std::cout << sum << std::endl;
	}
}