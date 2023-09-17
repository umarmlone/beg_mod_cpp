// SharedPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class Project
{
    std::string M_name;
public:
    void Setname(const std::string& name)
    {
        M_name = name;
    }
    void showProjectinfo()
    {
        std::cout << "[project name] " << M_name << std::endl;
    }

};

class Employee
{
    std::shared_ptr<Project> prj{} ;
public:
    void setProject(std::shared_ptr<Project> ptr)
    {
        prj = ptr;
    }
    const std::shared_ptr<Project> getProjectinfo()const
    {
        std::cout << "a8a" << '\n';
        return prj;
    }

};
int main()
{
    std::cout << "Hello World!\n";

    std::shared_ptr<Project> prj{new Project{}};

    prj->Setname("a7a l shbshb");
    prj->showProjectinfo();
    std::unique_ptr<Employee> E1{new Employee{}};
    E1->setProject(prj);
    std::unique_ptr<Employee> E2{new Employee{}};
    E2->setProject(prj);
    std::unique_ptr<Employee> E3{new Employee{}};
    E3->setProject(prj);

    E1->getProjectinfo();
    E2->getProjectinfo();
    E3->getProjectinfo();

    std::cout << prj.use_count() << std::endl;
    E1.reset();
    E2.reset();
    std::cout << prj.use_count() << std::endl;
    /*delete E1
      delete E2
       delete E3*/
}


