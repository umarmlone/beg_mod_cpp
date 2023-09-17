#pragma once
#include <iostream>
class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer();

	//Parameterized constructor
	Integer(int value);

	//Copy constructor
	Integer(const Integer &obj);

	//Move constructor
	Integer(Integer &&obj);

	int GetValue()const;


	void SetValue(int value);
	
	~Integer();

	//adding operator overloading
	Integer operator +(const Integer& obj)const;

	//preIncrementing operator overloading
	Integer& operator ++();

	//postIncrementing operator overloading
	Integer& operator ++(int);

	//the equivalent operator overloading
	bool operator ==(const Integer& obj)const;

	//Copy assignment operator overloading
	Integer& operator =(const Integer& obj);

	//Move assignment operator overloading
	Integer& operator =(Integer&& obj);


	//creating a friend function to this class in order to access the private members of this class
	friend std::istream& operator>>(std::istream& input, Integer& obj);

	//friend class to access the other private member of Integer class
	friend class Printer;

};

class Printer {};