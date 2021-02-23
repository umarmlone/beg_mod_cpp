#include "Integer.h"
#include <memory>
class Project {
public:
	~Project() {
		std::cout << "~Project()" << std::endl; 
	}
};
class Employee {
	std::shared_ptr<Project> m_pProject ;
public:
	void SetProject(std::shared_ptr<Project> p) {
		m_pProject = p ;
	}
	std::shared_ptr<Project> GetProject()const {
		return m_pProject ;
	}
	~Employee() {
		std::cout << "~Employee()" << std::endl; 
	}
};
std::shared_ptr<Employee> AssignProject() {
	std::shared_ptr<Project> p{new Project{}} ;
	Employee *e1 = new Employee{} ;
	e1->SetProject(p) ;
	/*
	 * ======= NOTE =======
	 * Avoid assigning a raw pointer to a smart pointer.
	 * Instead, use new expression directly inside
	 * the smart pointer ctor e.g. std::shared_ptr<int> p{new int} ;
	 * 
	 * The following code is just for demonstration.
	 */
	return std::shared_ptr<Employee>{e1} ;
}
int main() {
	auto sp = AssignProject() ;
	if(sp == nullptr) {
		
	}
	sp.get() ;
	sp.reset(new Employee{}) ;
}