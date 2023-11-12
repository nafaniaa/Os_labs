#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "ConsoleInformation.h"
#include <mutex> //The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.
#include <thread> //Class to represent individual threads of execution.

class BankAccount
{
private:
	float value;
	std::mutex mtx1; 

public:
	BankAccount();
	BankAccount(float);
	void modification(float operation);
	float getValue();
};


#endif//BANKACCOUNT_H
