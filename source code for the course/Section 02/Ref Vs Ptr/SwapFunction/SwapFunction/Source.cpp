#include <iostream>
/*
Difficult to use and prone to errors
Also needs a null check
*/
void Swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Easy to use and no null check required
void Swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
int main() {
	using namespace std;
	int a = 5, b = 10;
	Swap(a, b);
	cout << "a:" << a << "\n";
	cout << "b:" << b << "\n";
	return 0;
}