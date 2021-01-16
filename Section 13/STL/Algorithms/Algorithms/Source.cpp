#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
class Employee {
	std::string m_Name;
	int m_Id;
	std::string m_ProgLang;
public:
	Employee(const std::string &n, int id, const std::string &pl) :
		m_Name(n), 
		m_Id(id),
		m_ProgLang(pl){

	}
	const std::string & GetName()const {
		return m_Name;
	}
	int GetId()const {
		return m_Id;
	}
	const std::string & GetProgrammingLanguage()const {
		return m_ProgLang;
	}
	//bool operator <(const Employee &e)const {
	//	return m_Id < e.m_Id;
	//}
};
struct EmpIds {
	std::vector<int> m_Ids;
	void operator()(const Employee &emp) {
		if (emp.GetProgrammingLanguage() == "C++")
			m_Ids.push_back(emp.GetId());
	}
};
void UserDefined() {
	std::vector<Employee> v{
		Employee{ "Umar", 101, "C++" },
		Employee{ "Bob", 202, "Java"},
		Employee{ "Joey", 200, "C++"}
	};
	//Use callback to avoid overloading comparison operators
	std::sort(v.begin(), v.end(), [](const auto &e1, const auto &e2) {
		return e1.GetName() < e2.GetName();
	});
	for (const auto &e : v) {
		std::cout 
			<< "Id:" << e.GetId() 
			<< " | Name:" << e.GetName() 
			<< " | Language:" << e.GetProgrammingLanguage() << std::endl;
	}

	int cppCount{};
	//for (const auto &e : v) {
	//	if (e.GetProgrammingLanguage() == "C++")
	//		++cppCount;
	//}

	//Terse, but gives more information to the reader as compared to a for loop
	cppCount = std::count_if(v.begin(), v.end(), [](const auto &e) {
		return e.GetProgrammingLanguage() == "C++";
	});
	std::cout << "Count:" << cppCount << std::endl;

	//Find if any employee knows Java
	auto itr = std::find_if(v.begin(), v.end(), [](const auto &e) {
		return e.GetProgrammingLanguage() == "Java";
	});
	if (itr != v.end()) {
		std::cout << "Found:" << itr->GetName() << " is a Java programmer" << std::endl;
	}
	//Print all employee names
	std::for_each(v.begin(), v.end(), [](const auto &e) {
		std::cout << e.GetName() << std::endl;
	});

	//Get ids of all employees that know C++
	auto foundIds = std::for_each(v.begin(), v.end(), EmpIds());
	for (int id : foundIds.m_Ids) {
		std::cout << "Id:" << id << std::endl;
	}
	
}
//Custom comparator for associative containers
struct EmpCompare {
	bool operator ()(const Employee &e1, const Employee &e2)const {
		return e1.GetId() < e2.GetId();
	}
};
void Set() {
	//Using custom comparator
	std::set<Employee, EmpCompare> v{
		//				 ^^^^
		Employee{ "Umar", 101, "C++" },
		Employee{ "Bob", 202, "Java" },
		Employee{ "Joey", 200, "C++" }
	};

	for (const auto &e : v) {
		std::cout
			<< "Id:" << e.GetId()
			<< " | Name:" << e.GetName()
			<< " | Language:" << e.GetProgrammingLanguage() << std::endl;
	}
}
int main() {
	Set();
	return 0;
}