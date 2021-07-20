#include <iostream>
namespace A{
	namespace B{
		namespace C{
		}
	}
}
namespace A::B::C{
	void Foo(){
	}
}

int main(){
	A::B::C::Foo() ;
	using A::B::C::Foo() ;
	using namespace A::B::C ;
	Foo() ;
}