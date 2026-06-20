// Write a program to ask the user to enter two numbers and an operation type (+, -, *, /), then calculate and print the result.
#include <iostream>
using namespace std;


enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };


void ReadNumbers(float &FirstNumber, float &SecondNumber)
{

	cout << "Please enter your first number : ";
	cin >> FirstNumber;

	cout << "Please enter your second number : ";
	cin >> SecondNumber;

}


enOperationType ReadType()
{
	char Operation;

	cout << "[+] add the two numbers." << endl;
	cout << "[-] subtract the two numbers." << endl;
	cout << "[*] multiply the two numbers." << endl;
	cout << "[/] divide the two numbers." << endl;
	cout << "Please enter your operation type : ";
	cin >> Operation;

	return enOperationType(Operation);
}


float Calculate(float FirstNumber, float SecondNumber, enOperationType Type)
{

	switch (Type)
	{
		case enOperationType::Add:
		return FirstNumber + SecondNumber;

	case enOperationType::Subtract:
		return FirstNumber - SecondNumber;

	case enOperationType::Multiply:
		return FirstNumber * SecondNumber;

	case enOperationType::Divide:
		return FirstNumber / SecondNumber;

	default:
		return FirstNumber + SecondNumber;
	}
	
}


void PrintResult(float FinalResult)
{
	cout << "The result is : " << FinalResult << endl;
}


int main()
{
	float FirstNumber, SecondNumber;
	ReadNumbers(FirstNumber, SecondNumber);

	PrintResult(Calculate(FirstNumber, SecondNumber, ReadType()));

}