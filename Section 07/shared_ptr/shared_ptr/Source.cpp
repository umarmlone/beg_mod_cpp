#include <iostream>
#include <memory>
#include <vector>

class Project {
    std::string m_Name;
public:
    void SetName(const std::string &name){
        m_Name = name;
    }
    void ShowProjectDetails()const{
        std::cout << "[Project Name]" << m_Name << '\n' ;
    }
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
void ShowInfo(const std::unique_ptr<Employee>& emp){
    std::cout << "Employee project details: ";
    emp->GetProject()->ShowProjectDetails();
}
class HR{
    std::vector<std::shared_ptr<Employee>> m_Employees{};
public:
    void AddEmployee(const std::shared_ptr<Employee> & emp){
        m_Employees.push_back(emp);
    }
    std::shared_ptr<Employee> GetEmployee(int index){
        return m_Employees[index];
    }
};
class Library{
    std::vector<std::shared_ptr<Employee>> m_Employees{};
public:
    void RegisterEmployee(const std::shared_ptr<Employee> & emp){
        m_Employees.push_back(emp);
    }


};
int main() {
	std::shared_ptr<Project> prj{ new Project{} };
    prj->SetName("Video Decoder") ;
    std::shared_ptr<Employee> e1 {new Employee{}} ;
    e1->SetProject(prj);
     std::shared_ptr<Employee> e2 {new Employee{}} ;
    e2->SetProject(prj);
     std::shared_ptr<Employee> e3 {new Employee{}} ;
    e3->SetProject(prj);

    HR hr{} ;
    Library lib{} ;
    hr.AddEmployee(e1) ;
    hr.AddEmployee(e2) ;
    hr.AddEmployee(e3) ;
    lib.RegisterEmployee(e1) ;

    if(e3){
        //Valid
    }else{
        //Not valid
    }
    
    std::cout << "Reference count:" << prj.use_count() << '\n' ;
    //ShowInfo(e1) ;
    //ShowInfo(e2) ;
    prj->ShowProjectDetails();

}
