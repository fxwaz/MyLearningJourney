// Write a program that asks the user to enter their mark, then prints "PASS" if the mark is >= 50, otherwise prints "FAIL".
#include <iostream>
using namespace std;

enum enPassOrFail { Pass = 1, Fail = 2};

int ReadMark()
{
	int Mark;

	cout << "Please enter your mark : ";
	cin >> Mark;

	return Mark;
}

enPassOrFail CheckMark(int Mark)
{

	if (Mark >= 50)
	{
		return enPassOrFail::Pass;
	}
	else
	{
		return enPassOrFail::Fail;
	}
		
}

void PrintResult(int Mark)
{

	if (CheckMark(Mark) == enPassOrFail::Pass)
	{
		cout << "\n\nNice bro, you passed!\n\n";
	}	
	else
	{
		cout << "\n\nSorry bro, you failed\n\n";
	}
		
}

int main()
{
	PrintResult(ReadMark());
}