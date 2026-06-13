// Write a program that asks the user to enter three numbers, then prints their sum.
#include <iostream>
using namespace std;


void ReadNumbers(int &first, int &second, int &third)
{

	cout << "Please enter first number : ";
	cin >> first;

	cout << "Please enter second number :";
	cin >> second;

	cout << "Please enter third number :";
	cin >> third;

	
}

int CalculateNumbers(int first, int second, int third)
{
	return first + second + third;
}

void PrintResult(int result)
{
	cout << "The result is : " << result << endl;
}

int main()
{

	int number1, number2, number3;

	ReadNumbers(number1, number2, number3);
	PrintResult(CalculateNumbers(number1, number2, number3));



}