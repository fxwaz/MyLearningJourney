// Write a program to read a string and read a character then count the character in that string (Match Case or Not)
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


enum enMatchCase { MatchCase = 1, NotMatchCase};


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

char InvertLetterCase(char UserChar)
{
	return isupper(UserChar) ? tolower(UserChar) : toupper(UserChar);
}

int CountCharInString(string Text, char Letter, enMatchCase MatchOrNot = enMatchCase::MatchCase)
{
	int HowMany = 0;
	char SmallLetter = tolower(Letter);

	for (int i = 0; i < Text.length(); i++)
	{
		if (MatchOrNot == enMatchCase::MatchCase)
		{
			if (Text[i] == Letter)
				HowMany++;
		}
		else
		{
			if (tolower(Text[i]) == SmallLetter)
				HowMany++;
		}
	}

	return HowMany;
}



int main()
{
	string UserText = ReadString();
	char UserChar = ReadChar();


	cout << "\nLetter '" << UserChar << "' Count = ";
	cout << CountCharInString(UserText, UserChar) << endl;

	cout << "Letter '" << UserChar << "' or '" << InvertLetterCase(UserChar) << "' Count = ";
	cout << CountCharInString(UserText, UserChar, enMatchCase::NotMatchCase) << endl;

}