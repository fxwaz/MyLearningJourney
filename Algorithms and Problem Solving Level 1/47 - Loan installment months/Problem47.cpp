// Write a program to read a LoanAmount and MonthlyPayment and calculate how many months you need to settle the loan.
#include <iostream>
using namespace std;


struct stLoanInfo
{
	float LoanAmount;
	float MonthlyPayment;
};


float ReadPositiveNumber(string MainMessage, string ErrorMessage)
{
	float UserNumber;

	do
	{
		cout << MainMessage;
		cin >> UserNumber;

		if (UserNumber <= 0)
		{
			cout << ErrorMessage;
		}

	} while (UserNumber <= 0);

	return UserNumber;
}


stLoanInfo ReadLoanInfo()
{

	stLoanInfo LoanInfo;
	LoanInfo.LoanAmount = ReadPositiveNumber("Please enter loan amount : ", "Wrong! u have to enter only positive number\n");
	LoanInfo.MonthlyPayment = ReadPositiveNumber("Please enter monthly installment : ", "Wrong! u have to enter only positive number\n");

	return LoanInfo;

}

float CalculateTotalMonths(stLoanInfo LoanInfo)
{
	return LoanInfo.LoanAmount / LoanInfo.MonthlyPayment;
}

void PrintResult(float TotalMonths)
{
	cout << TotalMonths << " Months" << endl;
}

int main()
{
	PrintResult(CalculateTotalMonths(ReadLoanInfo()));

}