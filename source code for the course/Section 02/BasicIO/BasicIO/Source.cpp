#include <iostream>

int main() {
	using namespace std;
	
	char buff[512];
	cout << "What is your name?";
	/*
	There's a better way to do it. Check the 
	lecture on std::strings if you're curious :)
	*/
	cin.getline(buff, 64, '\n');
	cout << "Your name is:" << buff << endl;
	
	int age ;
	cin >> age ;
	return 0;
}