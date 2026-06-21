// Write a program to read a LoanAmount and ask you how many months you need to settle the loan, then calculate the monthly installment amount.
#include <iostream>
using namespace std;


struct stLoanInfo
{
	float LoanAmount;
	float NumberOfMonths;
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
	LoanInfo.NumberOfMonths = ReadPositiveNumber("Please enter how many months u want : ", "Wrong! u have to enter only positive number\n");

	return LoanInfo;

}


float CalculateMonthlyPayment(stLoanInfo LoanInfo)
{
	return LoanInfo.LoanAmount / LoanInfo.NumberOfMonths;
}


void PrintResult(float Payment)
{
	cout << "\n" << Payment << " Monthly" << endl;
}


int main()
{
	PrintResult(CalculateMonthlyPayment(ReadLoanInfo()));
}