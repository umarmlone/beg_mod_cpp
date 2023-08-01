#include <iostream>
//Old Code
//int Max(int x, int y) {
//	return x > y ? x : y;
//}
//float Max(float x, float y) {
//	return x > y ? x : y;
//}

//Primary Template
template<typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}
//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specialization
template<> const char * Max<const char*>(const char *x, const char *y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

void Examples() {
#pragma region Instantiation Examples
	Max(static_cast<float>(3), 5.5f);

	//Override compiler's deduction process
	Max<double>(3, 6.2);

	//Causes implicit instantiation of Max<int>
	int(*pfn)(int, int) = Max;

#pragma endregion
#pragma region Explicit Instantiation
	const char *b{ "B" };
	const char *a{ "A" };
	auto s = Max(a, b);
	std::cout << s << std::endl;
#pragma endregion
}

//Non-type template parameter
template<int size>
void Print() {
	char buffer[size];
	std::cout << size << std::endl;
}
//Requires size as explicit argument
template<typename T>
T Sum(T*parr, int size){
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
//Size is implicitly calculated in non-type template argument
template<typename T,int size>
T Sum(T (&arr)[size]) {
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
int main() {
	Print<3>();
	int arr[]{ 3,1,9,7 };
	//int (&ref)[5] = arr ;
	int sum = Sum(arr);
	std::cout << sum << std::endl; 
	return 0;
}