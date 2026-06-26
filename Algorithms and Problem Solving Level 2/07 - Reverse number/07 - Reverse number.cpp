// Write a program to read a number and print it reversed.
#include <iostream>
using namespace std;


int ReadPositiveNumber(string Message)
{
	int UserNumber;

	do
	{
		cout << Message;
		cin >> UserNumber;

	} while (UserNumber <= 0);

	return UserNumber;
}

int ReverseNumber(int UserNumber)
{
	int Remainder = 0;
	int Reverse = 0;


	while (UserNumber > 0)
	{
		Remainder = UserNumber % 10; 
		UserNumber = UserNumber / 10; 
		Reverse = Reverse * 10 + Remainder; 
		// ليه نضرب في 10 ؟ لأننا نبي نحرك الرقم المعكوس عشان نضيف الرقم الجديد في خانة الآحاد
	}

	return Reverse;

}

void PrintResult(int Reverse)
{

	cout << "The reverse is : " << Reverse << endl;

}

int main()
{

	PrintResult(ReverseNumber(ReadPositiveNumber("Please enter a positive number : ")));

}