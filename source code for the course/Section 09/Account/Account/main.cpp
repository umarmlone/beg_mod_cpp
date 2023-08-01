#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>
int main()
{
	Checking ch("Bob", 100, 50);
	Transact(&ch);

    return 0;
}
 
