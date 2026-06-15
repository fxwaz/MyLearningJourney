// Write a program that asks the user to enter two numbers, prints them, then swaps their values and prints them again.
#include <iostream>
using namespace std;


void ReadNumbers(int& number1, int& number2)
{
	cout << "Please enter number one : ";
	cin >> number1;

	cout << "Please enter number two : ";
	cin >> number2;
}

void SwapNumbers(int &number1, int &number2)
{

	int SwapBox;
	SwapBox = number1;
	number1 = number2;
	number2 = SwapBox;

}

void PrintResult(int number1, int number2)
{
	
	cout << "\nNumber one " << number1 << " Number two " << number2 << endl;

}



int main()
{

	int number1, number2;

	ReadNumbers(number1, number2);
	PrintResult(number1, number2);
	SwapNumbers(number1, number2);
	PrintResult(number1, number2);

}






/*


I can also do this:


void PrintResult(string message, int number1, int number2)
{
	cout << message << endl;
	cout << "Number one " << number1 << " Number two " << number2 << endl;

}



int main()
{
	int number1, number2;

	ReadNumbers(number1, number2);
	PrintResult("\nNumbers Before Swap :",number1, number2);
	SwapNumbers(number1, number2);
	PrintResult("\nNumbers After Swap : ",number1, number2);
}


*/