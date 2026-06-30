// write a program to read a text and encrypt it, decrypt it.
#include <iostream>
using namespace std;


string ReadText(string Text)
{
	string UserText; 

	cout << Text;
	cin >> UserText;

	return UserText;
}

int CheckLength(string UserText)
{
	return UserText.length();
}

string EncryptText(string Text)
{
	int TextLength = Text.length() - 1;
	string NewText = "";

	for (int i = 1; i <= TextLength; i++)
	{
		NewText = NewText + Text[0+1];
	}

	return NewText;
}

int main()
{
	string Name = "Fawaz";

	Name[0] = 68;

	cout << Name;
}
