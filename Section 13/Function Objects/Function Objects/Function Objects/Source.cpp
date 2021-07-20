#include <iostream>
//using Comparator = bool(*)(int, int);
template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size-1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}
//Function pointers as comparators
bool Comp(int x, int y) {
	return x > y;
}
bool Comp1(int x, int y) {
	return x < y;
}


//Function Object as comparator
struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};
int main() {
	Comp(3, 5);
	Comp2 comp;
	comp(3, 5);//comp.operator()(3,5) ;
	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	Sort(arr, comp);
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}