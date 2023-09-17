#include <iostream>
#include <list>
#include <thread>
#include <string>
std::list<int> g_Data;
const int SIZE = 5000000;
class String {
public:
	String() {
		std::cout << "String()" << std::endl;
	}
	String(const String &) {
		std::cout << "String(const String&)" << std::endl;
	}
	String & operator=(const String&) {
		std::cout << "operator=(const String&)" << std::endl;

		return *this;
	}
	~String() {
		std::cout << "~String()" << std::endl;
	}
};
void Download(const String &file) {
	//std::cout << "[Downloader]Started download of file :" << file << std::endl; 
	for (int i = 0; i < SIZE; ++i) {
		g_Data.push_back(i);
	}
	std::cout << "[Downloader]Finished download" << std::endl; 
}
int main() {
	String file;
	std::cout << "[main]User started an operation" << std::endl; 
	//use std::ref and std::cref to pass arguments as reference & const reference, respectively
	std::thread thDownloader(Download,std::cref(file) );
	//thDownloader.detach();

	std::cout << "[main]User started another operation" << std::endl;
	//Always check before joining a thread
	if (thDownloader.joinable()) {
		thDownloader.join() ;
	}
	//system("Pause");
	return 0;
}