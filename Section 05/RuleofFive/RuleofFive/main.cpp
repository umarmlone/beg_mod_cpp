#include "Integer.h"
class Number{
	Integer m_Value{} ;
public:
	Number()=default ;
	Number(int value):m_Value{value}{
	}
	/*Number(const Number &n):m_Value{n.m_Value}{
	}*/
	/*~Number(){
	}*/
	Number(Number &&n) = default ;
	Number(const Number &n) = default ;
	Number & operator=(Number&&)=default ;
	Number & operator=(const Number&)=default ;
};
Number CreateNumber(int num){
	Number n{num} ;
	return n ;
}
int main(){
	Number n1 ;
	auto n2{n1} ;
	n2 = n1 ;

	auto n3{CreateNumber(3)} ;
	n3 = CreateNumber(3) ;
}
