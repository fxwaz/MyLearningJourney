#include <iostream>
using namespace std;


int ReadNumber(string Message)
{
	int UserNumber;

	cout << Message;
	cin >> UserNumber;

	return UserNumber;

}


int main()
{

	// Using If Statement

	int Mark = 90;
	string Result;

	if (Mark >= 50)
		Result = "Pass";
	else
		Result = "Fail";

	cout << Result << endl;


	/*

	 Using Ternary Operator

			 (condition)  ? value_if_true : value_if_false;
	*/
	Result = (Mark >= 50) ? "Pass" : "Fail";

	cout << Result << endl;



	// Write a program to check if the number is Positive or Negative using Ternary Operator

	int FirstUserNumber = ReadNumber("Please enter a number : ");
	string FirstResult;

	FirstResult = (FirstUserNumber > 0) ? "Positive" : "Negative";

	cout << FirstResult << endl;


	// Write a program to check if the number is Zero, Positive, or Negative. (Use nested Ternary Operators)

	int SecondUserNumber = ReadNumber("Please enter a number : ");
	string SecondResult;

	SecondResult = (SecondUserNumber == 0) ? "Zero" : (SecondUserNumber > 0) ? "Positive" : "Negative";

	cout << SecondResult << endl;
}