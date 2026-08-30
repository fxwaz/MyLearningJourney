// Write a program to read a character then invert its case and print it.
#include <iostream>
#include <cctype>
using namespace std;



char ReadChar()
{
	char UserChar;

	cout << "Please Enter Your Char : ";
	cin >> UserChar;

	return UserChar;
}

char InvertLetterCase(char UserChar)
{
	return isupper(UserChar) ? tolower(UserChar) : toupper(UserChar);
}



int main()
{
	char UserChar = ReadChar();

	UserChar = InvertLetterCase(UserChar);
	cout << UserChar << endl;
}