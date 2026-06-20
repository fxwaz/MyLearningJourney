// Read numbers from the user and keep summing them until the user enters -99.
#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string Message)
{

	int UserNumber;

	cout << Message;
	cin >> UserNumber;

	return UserNumber;
}


int SumNumbersUntil99()
{
	int UserNumber;
	int counter = 1;
	int SumBox = 0;

	do
	{
		UserNumber = ReadNumber("Please enter number " + to_string(counter) + " : ");

		if (UserNumber != -99)
		{
			SumBox = SumBox + UserNumber;
			counter++;
		}

	
	} while (UserNumber != -99);

	return SumBox;
}


void PrintResult(int result)
{

	cout << "The sum is = " << result << endl;

}

int main()
{
	PrintResult(SumNumbersUntil99());
}
