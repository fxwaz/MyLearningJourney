// Write a program that asks the user to enter three numbers, then prints the largest number.
#include <iostream>
using namespace std;


void ReadNumbers(int& number1, int& number2, int& number3)
{

	cout << "Please enter number one : ";
	cin >> number1;

	cout << "Please enter number two : ";
	cin >> number2;

	cout << "Please enter number three : ";
	cin >> number3;

}

int GetMaxNumber(int number1, int number2, int number3)
{

	if (number1 >= number2 && number1 >= number3)
		return number1;
	else if (number2 >= number1 && number2 >= number3)
		return number2;
	else
		return number3;

}

void PrintResult(int result)
{
	cout << "The Maximum number is : " << result << endl;
}


int main()
{
	int number1, number2, number3;

	ReadNumbers(number1, number2, number3);
	PrintResult(GetMaxNumber(number1, number2, number3));
}