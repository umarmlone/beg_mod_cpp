#include "Checking.h"

#include <iostream>
Checking::Checking(const std::string &name, float balance, float minbalance):
m_MinimumBalance(minbalance), Account(name, balance){
}


Checking::~Checking() {
}

void Checking::Withdraw(float amount) {
	if ((m_Balance - amount) > m_MinimumBalance) {
		Account::Withdraw(amount);
	}
	else {
		std::cout << "Invalid amount" << std::endl; 
	}
}

float Checking::GetMinimumBalance() const {
	return m_MinimumBalance;
}
