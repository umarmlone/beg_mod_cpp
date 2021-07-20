#include <iostream>
class Printer {
	std::weak_ptr<int> m_pValue{} ;
public:
	void SetValue(std::weak_ptr<int> p) {
		m_pValue = p ;
	}
	void Print() {
		if(m_pValue.expired()) {
			std::cout << "Resource is no longer available" << std::endl;
			return ;
		}
		auto sp = m_pValue.lock() ;
		std::cout << "Value is:" << *sp << std::endl ;
		std::cout << "Ref count:" << sp.use_count() << std::endl ;
	}
};
int main() {
	Printer prn ;
	int num{} ;
	std::cin >> num ;
	std::shared_ptr<int> p{new int{num}} ;
	prn.SetValue(p) ;
	if(*p > 10) {
		p = nullptr ;
	}
	prn.Print() ;
}