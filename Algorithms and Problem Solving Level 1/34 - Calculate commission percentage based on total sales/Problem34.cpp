// Write a program to calculate commission percentage based on total sales.
#include <iostream>
using namespace std;


float ReadSales()
{
	float TotalSales;

	cout << "Please enter your total sales : ";
	cin >> TotalSales;

	return TotalSales;
}

float GetCommissionPercentage(float TotalSales)
{
	if (TotalSales >= 1000000)
		return 0.01;
	else if (TotalSales >= 500000)
		return 0.02;
	else if (TotalSales >= 100000)
		return 0.03;
	else if (TotalSales >= 50000)
		return 0.05;
	else 
		return 0.00;
}

float CalculateCommission(float TotalSales)
{
	return TotalSales * GetCommissionPercentage(TotalSales);
}

void PrintResult(float CommissionPercentage, float Commission)
{
	cout << "Your commission percentage is : " << CommissionPercentage * 100 << "%" << endl;
	cout << "Your commission is : " << Commission << endl;

}

int main()
{
	float TotalSales = ReadSales();

	PrintResult(GetCommissionPercentage(TotalSales),CalculateCommission(TotalSales));
}