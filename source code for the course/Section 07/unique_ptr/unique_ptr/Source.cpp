#include "integer.h"
#include <memory>
void Display(Integer *p) {
	if(!p) {
		return ;
	}
	std::cout << p->GetValue() << std::endl; 
}
Integer *GetPointer(int value) {
	Integer *p = new Integer{value} ;
	return p ;
}
void Store(std::unique_ptr<Integer> &p) {
	std::cout << "Storing data into a file:" << p->GetValue() << std::endl; 
}
void Operate(int value) {
	std::unique_ptr<Integer> p{GetPointer(value)} ;
	if(p == nullptr) {
		//p = new Integer{value} ;
		p.reset(new Integer{value}) ;
	}
	p->SetValue(100) ;
	Display(p.get()) ;
	//delete p ;
	//p = nullptr ;
	//p = new Integer{} ;
	p.reset(new Integer{}) ;
	*p = __LINE__ ;
	Display(p.get()) ;
	Store(p) ;
	//delete p ;
}
int main() {
	Operate(5) ;
}