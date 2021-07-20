#include <iostream>
#include <thread>
#include <Windows.h>
void Process() {
	//std::cout << "Threadid:" << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << ' ';
	}
}

int main() {
	std::thread t1(Process);
	//Returns the native type of the thread
	//On Linux, the native type is pthread_t
	HANDLE handle = t1.native_handle();
	SetThreadDescription(handle, L"MyThread");	
	auto id = t1.get_id();
	std::cout << "t1.get_id()" << id << std::endl; 

	int cores = std::thread::hardware_concurrency();

	std::cout << "Cores:" << cores << std::endl;
	t1.join();
	return 0;
}