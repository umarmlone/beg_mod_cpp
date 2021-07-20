#include "Integer.h"
#include <iostream>

Integer Add(const Integer &a, const Integer &b){
	Integer temp ;
	temp.SetValue(a.GetValue() + b.GetValue()) ;
}
int main() {
	Integer a(1), b(3) ;
	a.SetValue(Add(a,b).GetValue()) ;
	

	return 0;
}