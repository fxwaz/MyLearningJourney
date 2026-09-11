// Write a program to remove all punctuations from a string.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;



string ReadString()
{
	string UserString;

	cout << "Please enter your string : ";
	getline(cin, UserString);

	return UserString;
}

string RemovePunctuationsFromString(string Text)
{
	string NewString = "";

	for (int i = 0; i < Text.length(); i++)
	{
		if (!ispunct(Text[i]))
		{
			NewString = NewString + Text[i];
		}
	}

	return NewString;
}



int main()
{
	string UserString = ReadString();

	cout << RemovePunctuationsFromString(UserString);
}