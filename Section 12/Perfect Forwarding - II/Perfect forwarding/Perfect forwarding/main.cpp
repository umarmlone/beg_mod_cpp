#include "Integer.h"
#include <iostream>
#include <string>
class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	//Employee(const std::string &name, const Integer &id) :
	//	m_Name{ name },
	//	m_Id{ id } {
	//	std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	//}
	template<typename T1, typename T2>
	Employee(T1 &&name,  T2 &&id) :
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;

	}
};
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main() {
	//Employee emp1{ "Umar", Integer{100} };
	/*std::string name = "Umar";
	Employee emp2{ name, 100 };
	Integer val{ 100 };
	Employee emp3{ std::string{"Umar"}, val };*/
	auto emp = Create("Umar", Integer{ 100 });
	return 0;
}