#include "Integer.h"
#include <iostream>
Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) {
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const {
	return *m_pInt;
}

void Integer::SetValue(int value) {
	*m_pInt = value;
}

Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer Integer::operator +(const Integer & obj)const
{
	Integer temp;
	*temp.m_pInt = *m_pInt + *obj.m_pInt;
	return temp;
}

Integer& Integer::operator++()
{
	++(*m_pInt);  //incrementing the m_pointer value
	return (*this); // returns what's inside the pointer of this object
}

Integer& Integer::operator++(int)
{
	Integer temp(*this); //create a temp value with (this) pointer
	++(*m_pInt);   // pre increment  mpointer
	return temp; // return the temp before incrementing the mpointer
}

bool Integer::operator==(const Integer& obj) const
{
	return  (*obj.m_pInt == *m_pInt);
}

Integer& Integer::operator=(const Integer& obj)
{
	// TODO: insert return statement here
	if (*m_pInt != *obj.m_pInt)
	{
		delete m_pInt;
		m_pInt = new int(*obj.m_pInt);
	}
	return *this;
}

Integer& Integer::operator=(Integer&& obj)
{
	if (*m_pInt != *obj.m_pInt)
	{
		delete m_pInt;
		m_pInt = obj.m_pInt;
		obj.m_pInt = nullptr;
	}
	return *this;
}


