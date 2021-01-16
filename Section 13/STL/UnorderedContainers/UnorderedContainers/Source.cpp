#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
void UnSet() {
	std::unordered_multiset<std::string> coll;
	//elements are stored based on the hash, but in unspecified order, 
	coll.insert("Hulk");
	coll.insert("Batman");
	coll.insert("Green Lantern");
	coll.insert("The Flash");
	coll.insert("Wonder Woman");
	coll.insert("Iron man");
	coll.insert("Iron man");
	coll.insert("Iron man");
	coll.insert("Wolverine");
	coll.insert("Dr. Strange");
	coll.insert("Hawkman");

	
	for (const auto x : coll) {
		std::cout << "Bucket #:" << coll.bucket(x) << " contains :" << x << std::endl;
	}
	std::cout << "Bucket count:" << coll.bucket_count() << std::endl; 
	std::cout << "Number of elements:" << coll.size() << std::endl;
	std::cout << "Load factor:" << coll.load_factor() << std::endl ;
}
void UnMap() {
	std::unordered_multimap<std::string, std::string> coll;
	//Only unordered_map support [] operator
	/*coll["Batman"] = "Brue Wayne";
	coll["Superman"] = "Clark Kent";
	coll["Hulk"] = "Bruce Banner";*/
	coll.insert(std::make_pair("Batman", "Bruce Wayne"));
	coll.insert(std::make_pair("Batman", "Matches Malone"));
	coll.insert(std::make_pair("Superman", "Clark Kent"));
	coll.insert(std::make_pair("Hulk", "Bruce Banner"));

	for (const auto &x : coll) {
		std::cout << "Bucket #:" << coll.bucket(x.first) << " ->" << x.first << ":" << x.second << std::endl; 
	}
}
class Employee {
	std::string m_Name;
	int m_Id;
public:
	Employee(const std::string &n, int id) :m_Name(n), m_Id(id) {

	}
	const std::string & GetName()const {
		return m_Name;
	}
	int GetId()const {
		return m_Id;
	}
};

//Custom hash function
struct EmployeeHash {
	size_t operator()(const Employee & emp)const {
		auto s1 = std::hash<std::string>{}(emp.GetName());
		auto s2 = std::hash<int>{}(emp.GetId());
		return s1 ^ s2;
	}
};
//Custom function object for equality
struct EmpEquality {
	bool operator()(const Employee &e1, const Employee e2)const {
		return e1.GetId() == e2.GetId();
	}
};
void Hashes() {
	std::hash<std::string> h;
	//Hash is computed by the function object
	std::cout << "Hash:" << h("Hello") << std::endl;


	std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;
	coll.insert(Employee("Umar", 123));
	coll.insert(Employee("Bob", 678));
	coll.insert(Employee("Joey", 612));

	for (const auto &x : coll) {
		std::cout << x.GetId() << ":" << x.GetName() << std::endl;
	}
}
int main() {
	Hashes();
	return 0;
}