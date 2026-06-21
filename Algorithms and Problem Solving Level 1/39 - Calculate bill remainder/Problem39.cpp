// Write a program to read a TotalBill and CashPaid and calculate the remainder to be paid back.
#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(float& TotalBill, float& CashPaid)
{
	cout << "Please enter total bill : ";
	cin >> TotalBill;

	cout << "Please enter cash paid : ";
	cin >> CashPaid;
}

float CalculateRemainder(float TotalBill, float CashPaid)
{
		return CashPaid - TotalBill;
}

void PrintResult(float result)
{
	if (result > 0)
		cout << "\nYour remainder is : " << result << endl;
	else if (result < 0)
		cout << "\nYou have to pay more : " << -result << endl;
	else
		cout << "\nExact amount paid" << endl;
}

int main()
{
	float TotalBill, CashPaid;

	ReadNumbers(TotalBill, CashPaid);
	PrintResult(CalculateRemainder(TotalBill, CashPaid));
}