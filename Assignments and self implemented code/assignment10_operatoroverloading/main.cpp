#include "Integer.h"
#include <iostream>
#include <memory>

//making a global function as add operator overloading
Integer operator +(int x, const Integer& obj)
{
	Integer temp;
	temp.SetValue(x + obj.GetValue());
	return temp;
}

std::ostream& operator<<(std::ostream& output, const Integer& obj)
{
	output << obj.GetValue();
	return output;
}
std::istream& operator>>(std::istream& input, Integer& obj)
{
	int x;
	input >> x;
	//obj.SetValue(x);
	* obj.m_pInt = x;
	return  input;
	

}
int main() {
	Integer a(5);
	Integer b(5);
	Integer sum = a + b;
	std::cout << sum.GetValue() << std::endl;
	bool a7a = (a == ++(b));
	std::cout << a7a << std::endl;
	std::cout << b.GetValue() << std::endl;
	++sum;
	std::cout <<sum.GetValue() << std::endl;
	a = a;
	std::cout << a.GetValue() << std::endl;
	Integer sum1 = 9 + a;
	std::cout << "global op overloading : " <<sum1.GetValue() << std::endl;
	std::cout << sum1 << std::endl;
	Integer elgeded; 
	std::cin >> elgeded;
	std::cout << elgeded<< std::endl;
	return 0; 
}