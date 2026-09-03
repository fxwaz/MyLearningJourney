// Write a program to read a string then print each word in that string.
#include <iostream>
#include <string>
using namespace std;



string ReadString()
{
	string UserString;

	cout << "Please enter your string : ";
	getline(cin, UserString);

	return UserString;
}

void PrintEachWordInString(string Text)
{
	bool IsInWord = false;

	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			cout << Text[i];
			IsInWord = true;
		}
		else if (IsInWord)
		{
			cout << endl;
			IsInWord = false;
		}
	
	}
}


int main()
{
	PrintEachWordInString(ReadString());
}