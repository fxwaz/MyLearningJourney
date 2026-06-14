// Write a program that asks the user to enter two numbers, then prints the larger number.
#include <iostream>
using namespace std;


void ReadNumbers(int &number1, int &number2)
{

	cout << "Please enter number one : ";
	cin >> number1;

	cout << "Please enter number two : ";
	cin >> number2;

}

int GetMaxNumber(int number1, int number2)
{

	if (number1 > number2)
		return number1;
	else
		return number2;
	
}

void PrintResult(int MaxNumber)
{
	cout << "Max number is : " << MaxNumber << endl;
}

int main()
{
	int number1, number2;

	ReadNumbers(number1, number2);
	PrintResult(GetMaxNumber(number1, number2));
}