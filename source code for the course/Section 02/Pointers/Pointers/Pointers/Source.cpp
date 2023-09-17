#include <iostream>

int main() {
	using namespace std;
	int x = 10;
	cout << &x << "\n";
	int *ptr = nullptr;
	//cout << *ptr << "\n";
	*ptr = 10 ;
	return 0; 
}