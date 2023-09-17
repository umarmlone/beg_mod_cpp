#include <iostream>
#include "Integer.h"
class Product{
	Integer m_Id ;
public:
	Product(const Integer &id):m_Id{id} {
		std::cout << "Product(const Integer &)" << std::endl; 
	}
	~Product(){
		std::cout << "~" ;
	}
	const Integer & GetInteger()const{
		return m_Id ;
	}
	operator Integer(){
		return m_Id ;
	}
};

int main() {
	Product p{5} ;
	Integer id{5} ;
	//id = p ; // id = p.operator Integer() ;

	if(id == p){
		std::cout << "Id matches with the product\n" ;
	}

	return 0;
}