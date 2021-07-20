#include <iostream>
#include <fstream>
#include <filesystem>
void Alloc() {
	int* p = malloc(sizeof(int));
	if (p != nullptr) {
		*p = 50;
		free(p);
	}
	//if (initializationj condition) {
	if (int* p = (int*)malloc(sizeof(int)); p != nullptr) {
		*p = 50;
		free(p);
	}
	else {
		//Here p will be nullptr
	}
}
void Write(std::string data) {
	std::ofstream out{ "file.txt" };
	if (out) {
		if (data.empty()) {
			std::cout << data;
		}
		else {
			std::cout << "No data to write ";
		}
	}
	if (std::ofstream out{ "file.txt" }; !data.empty()) {
		std::cout << data;
	}
	else {
		std::cout < < "no data to write \n";
	}
}

void UsingSwitch(int errorCode) {
	switch (std::ofstream out{ "file.txt" }; errorCode) {
	case 0:
		out << "Invalid parameter";
		break;
	case 1:
		out << "Could not read from file";
		break;
	}
}
int main(){
	UsingSwitch() ;
}