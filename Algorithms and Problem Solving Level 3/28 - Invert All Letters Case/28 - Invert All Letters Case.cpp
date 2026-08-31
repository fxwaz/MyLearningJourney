// Write a program to read a string then invert all its letter's case and print it.
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

char InvertLetterCase(char UserChar)
{
	return isupper(UserChar) ? tolower(UserChar) : toupper(UserChar);
}

string InvertAllStringLettersCase(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = InvertLetterCase(Text[i]);
	}

	return Text;
}


int main()
{
	string MyText = ReadString();

	cout << "\nString after inverting all letters case : \n";
	MyText = InvertAllStringLettersCase(MyText);

	cout << MyText << endl;
}