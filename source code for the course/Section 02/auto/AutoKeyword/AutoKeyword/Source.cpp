#include <iostream>
int Sum(int x, int y) {
	return x + y;
}
int main() {
	//One of my favorite features of C++11 ;)
	auto i = 10;
	auto j = 5;
	auto sum = i + 4.3f;

	auto result = Sum(i, j);
	static auto y = 2;
	const int x = 10;
	//Works with qualifiers
	const auto var = x;
	//Deduced to reference
	auto &var1 = x;

	//Deduced to a pointer. * is not necessary
	auto *ptr = &x;
	return 0;
}