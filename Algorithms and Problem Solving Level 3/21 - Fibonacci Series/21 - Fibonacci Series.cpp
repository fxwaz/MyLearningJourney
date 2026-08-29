// Write a program to print Fibonacci Series of 10.
#include <iostream>
using namespace std;



void PrintFibonacciUsingLoop(int HowMany)
{
	int Slot1 = 0;
	int Slot2 = 1;
	int NextNumber = 0;

	cout << "1   ";

	for (int i = 2; i <= HowMany; i++)
	{

		NextNumber = Slot1 + Slot2;

		cout << NextNumber << "   ";
		Slot1 = Slot2;   
		Slot2 = NextNumber; 

	}
}


int main()
{

	PrintFibonacciUsingLoop(10);
}