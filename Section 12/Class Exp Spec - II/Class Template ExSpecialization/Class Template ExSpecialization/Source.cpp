#include <iostream>
#include <vector>
template<typename T>
class PrettyPrinter {
	T *m_pData;
public:
	PrettyPrinter(T *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};

//Explicit specialization of a member function should appear outside the class
template<>
void PrettyPrinter<std::vector<int>>::Print() {
	std::cout << "{";
	for (const auto &x : *m_pData) {
		std::cout << x;
	}
	std::cout << "}" << std::endl;
}
template<>
class PrettyPrinter<char*> {
	char *m_pData;
public:
	PrettyPrinter(char *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	char * GetData() {
		return m_pData;
	}
};

//template<>
//class PrettyPrinter<std::vector<int>> {
//	std::vector<int> *m_pData;
//public:
//	PrettyPrinter(std::vector<int> *data) :m_pData(data) {
//
//	}
//	void Print() {
//		std::cout << "{";
//		for (const auto &x : *m_pData) {
//			std::cout << x;
//		}
//		std::cout << "}" << std::endl;
//	}
//	std::vector<int> * GetData() {
//		return m_pData;
//	}
//};
int main() {
	//int data = 5;
	//float f = 8.2f;
	//PrettyPrinter<int> p1(&data);
	//p1.Print();
	//PrettyPrinter<float> p2(&f);
	//p2.Print();

	char *p{ "Hello world" };
	PrettyPrinter<char*> p3(p);
	p3.Print();
	char *pData = p3.GetData();
	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	pv.Print();
	return 0;
}