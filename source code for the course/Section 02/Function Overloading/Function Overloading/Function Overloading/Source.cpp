#include <iostream>
int Add(int a, int b) {
	return a + b;
}
double Add(double a, double b) {
	return a + b;
}
extern "C" void Print(int *x) {

}
void Print(const int* x) {

}
int main() {
	using namespace std;
	int result = Add(3, 5);
	cout << result << endl;
	Add(3.1, 6.2);
	const int x = 1;
	Print(&x);
	return 0;
}