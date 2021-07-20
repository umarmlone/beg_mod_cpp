#include "Account.h"
#include <iostream>
int Account::s_ANGenerator = 1000;
Account::Account(const std::string &name, float balance):
m_Name(name), m_Balance(balance){
	m_AccNo = ++s_ANGenerator;
	//std::cout << "Account(const std::string &, float)" << std::endl; 
}


Account::~Account() {
	//std::cout << "~Account()" << std::endl;

}

const std::string Account::GetName() const {
	return m_Name;
}

float Account::GetBalance() const {
	return m_Balance;
}

int Account::GetAccountNo() const {
	return m_AccNo;
}

void Account::AccumulateInterest() {
}

void Account::Withdraw(float amount) {
	/*
	Balance should be greater than 0 & the amount
	to withdraw should be less than balance
	*/
	if (amount < m_Balance && m_Balance > 0)
		m_Balance -= amount;
	else {
		//Throw an exception instead of printing a message
		//std::cout << "Insufficient balance" << std::endl;
		throw std::runtime_error("Insufficient balance");
	}
}

void Account::Deposit(float amount) {
	m_Balance += amount;
}

float Account::GetInterestRate() const {
	return 0.0f;
}
