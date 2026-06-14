// Write a program that asks the user to enter marks for three exams then print the average and print "PASS" if the average is greater than or equal to 50, otherwise print "FAIL".
#include <iostream>
using namespace std;

enum enPassFail { Pass = 1, Fail };


void ReadMarks(int& mark1, int& mark2, int& mark3)
{
	cout << "Please enter first mark : ";
	cin >> mark1;

	cout << "Please enter second mark : ";
	cin >> mark2;

	cout << "Please enter third mark : ";
	cin >> mark3;
}

int SumMarks(int mark1, int mark2, int mark3)
{
	return mark1 + mark2 + mark3;
}

float CalculateAverage(int mark1, int mark2, int mark3)
{
	return float(SumMarks(mark1, mark2, mark3)) / 3;
}

enPassFail CheckAverage(float average)
{
	if (average >= 50)
	{
		return enPassFail::Pass;
	}
	else
	{
		return enPassFail::Fail;
	}
}

void PrintResult(float result)
{

	cout << "Your average is : " << result << endl;

	if (CheckAverage(result) == enPassFail::Pass)
	{
		cout << "Pass !" << endl;
	}
	else
	{
		cout << "Fail !" << endl;
	}

}

int main()
{
	int mark1, mark2, mark3;

	ReadMarks(mark1, mark2, mark3);
	PrintResult(CalculateAverage(mark1, mark2, mark3));


}