// Write a program to read a BillValue and add service fee and sales tax to it, and print the TotalBill on the screen.
#include <iostream>
using namespace std;


float ReadBillValue()
{

	float BillValue;

	cout << "Please enter bill value : ";
	cin >> BillValue;

	return BillValue;

}

float CalculateServiceFeeAndSalesTax(float billvalue)
{

	float ServiceFeeRate = 0.10;
	float SalesTaxRate = 0.16;


	float ServiceFee = ServiceFeeRate * billvalue;
	float SalesTax = (ServiceFee + billvalue) * SalesTaxRate;

	return SalesTax + ServiceFee + billvalue;

}

void PrintResult(float result)
{
	cout << "Your bill is = " << result << endl;
}

int main()
{
	PrintResult(CalculateServiceFeeAndSalesTax(ReadBillValue()));
}