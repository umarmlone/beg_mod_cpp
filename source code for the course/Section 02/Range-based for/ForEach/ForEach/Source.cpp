#include <iostream>
int main() {
	using namespace std;
	int arr[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	for (const auto & x : arr) {
		
		cout << x << " ";
	}
	for (auto x : { 1,2,3,4 }) {
		cout << x;
	}
	return 0;
}