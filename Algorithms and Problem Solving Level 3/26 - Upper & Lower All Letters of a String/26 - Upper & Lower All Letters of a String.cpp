// Write a program to read a string then upper all letters, then lower all letters , and print them.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;



string ReadString()
{
	string UserString;

	cout << "Please Enter Your String : ";
	getline(cin, UserString);

	return UserString;
}

void UpperAllLetters(string &Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}
}

void LowerAllLetters(string &Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}
}



int main()
{
	string Text = ReadString();

	cout << "\nString after Upper : \n";
	UpperAllLetters(Text);
	cout << Text << endl;

	cout << "\nString after Lower : \n";
	LowerAllLetters(Text);
	cout << Text << endl;
}