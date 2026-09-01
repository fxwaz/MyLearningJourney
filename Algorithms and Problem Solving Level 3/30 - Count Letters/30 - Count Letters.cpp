// Write a program to read a string and read a character then count the character in that string.
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

char ReadChar()
{
	char UserChar;

	cout << "Please enter your char : ";
	cin >> UserChar;

	return UserChar;
}

int CountCharInString(string Text, char Letter)
{
	int HowMany = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] == Letter)
			HowMany++;
	}

	return HowMany;
}



int main()
{
	string UserText = ReadString();
	char UserChar = ReadChar();

	cout << "\nLetter '" << UserChar << "' Count = ";
	cout << CountCharInString(UserText, UserChar) << endl;
}
