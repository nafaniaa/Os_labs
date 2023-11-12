#include "BankAccount.h"

BankAccount::BankAccount()
{
	value = 0;
}

BankAccount::BankAccount(float initialValue)
{
	this->value = initialValue;
}

void BankAccount::modification(float operation){
	std::lock_guard<std::mutex> mtxGuard(mtx1); 

	//��� ����
	/*������� ������������� ������������� ���������� ������ ������� 
	� ����� �� ������� � ������ � ����� � ��� �� ������� ������ .*/

	ConsoleInformation::seblemenceOfCalculations();
	std::this_thread::sleep_for(std::chrono::milliseconds(75));
	float valueBefore = this->value;
	this->value += operation;
	float valueAfter = this->value;

	ConsoleInformation::accountModification(valueBefore, operation, valueAfter);
}

float BankAccount::getValue()
{
	std::lock_guard<std::mutex> mtxGuard(mtx1);
	return value;
}
