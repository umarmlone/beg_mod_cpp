#include <iostream>
#include <initializer_list>
#include <cassert>
class Bag {
	int arr[10];
	int m_Size{};
public:
	//Provides uniform initialization support for braced list of elements as arguments
	Bag(std::initializer_list<int> values) {
		assert(values.size() < 10);
		auto it = values.begin();
		while (it != values.end()) {
			Add(*it);
			++it;
		}
	}
	void Add(int value) {
		assert(m_Size < 10);
		arr[m_Size++] = value;
	}
	void Remove() {
		--m_Size;
	}
	int operator [](int index) {
		return arr[index];
	}
	int GetSize()const {
		return m_Size;
	}
};
void Print(std::initializer_list<int> values) {
	//auto it = values.begin();
	//while (it != values.end()) {
	//	std::cout << *it++ << " ";
	//}
	for (auto x : values) {
		std::cout << x << " ";
	}
}
int main() {
	int x{ 0 };
	float y{ 3.1f };
	int arr[5]{ 3,1,3,8,2 };
	std::string s{ "Hello C++" };
	std::initializer_list<int> data = { 1,2,3,4 };
	//Braced list of elements automatically creates an initializer_list object
	auto values = { 1,2,3,4 };

	//Bag b{ 3,1,8 };
	////b.Add(3);
	////b.Add(1);
	////b.Add(8);
	//for (int i = 0; i < b.GetSize(); ++i) {
	//	std::cout << b[i] << " "; 
	//}

	//Print({ 8,2,6,7 });
	for (auto x : { 8,2,6,7 }) {
		std::cout << x << " ";
	}
	return 0;
}