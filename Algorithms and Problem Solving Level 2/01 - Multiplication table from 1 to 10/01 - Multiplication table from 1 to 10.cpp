// Write a program to print Multiplication from 1 to 10
#include <iostream>
using namespace std;



void PrintTableHeader()
{
	cout << "\n\t\t\tMultiplication Table From 1 To 10\n\n";

	for (int i = 1; i <= 10; i++)
	{
		cout << "\t " << i;
	}

	cout << "\n-----------------------------------------------------------------------------------" << endl;
}

string ColumSperator(int i)
{
	if (i < 10)
		return "    |  ";
	else
		return "   |  ";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();

	for (int i = 1; i <= 10; i++)
	{

		cout << i << ColumSperator(i);

		for (int j = 1; j <= 10; j++)
		{
			cout << " " << i * j << "\t";
		}

		cout << endl;


	}

}





int main()
{
	PrintMultiplicationTable();
}