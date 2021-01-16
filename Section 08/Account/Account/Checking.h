#pragma once
#include "Account.h"
class Checking :
	public Account {
	float m_MinimumBalance;
public:
	using Account::Account;
	Checking(const std::string &name, float balance, float minbalance);
	~Checking();
	void Withdraw(float amount)override;
	float GetMinimumBalance()const;
};

