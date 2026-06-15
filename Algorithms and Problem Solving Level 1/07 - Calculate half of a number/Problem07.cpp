// Write a program that asks the user to enter a number, then prints half of that number.
#include <iostream>
#include <string>
using namespace std;



int ReadNumber()
{

	int UserNumber;

	cout << "Please enter a number : ";
	cin >> UserNumber;

	return UserNumber;
}

float CalculateHalfNumber(int usernumber)
{
	return float(usernumber) / 2;
}

void PrintResult(int number)
{
	string Result;

	Result = "Half of " + to_string(number) + " Is : " + to_string(CalculateHalfNumber(number));

	cout << Result << endl;
}


int main()
{
	
	PrintResult(ReadNumber());
	

}