// Write a program to read a string then count all vowels in that string (Vowels are : a, e, i, o, u)
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

bool IsVowel(char Letter)
{
	char ConvertToSmall = tolower(Letter);

	return (ConvertToSmall == 'a' || ConvertToSmall == 'e' || ConvertToSmall == 'i' || ConvertToSmall == 'o' || ConvertToSmall == 'u');

}

int CountVowelsInString(string Text)
{
	int Counter = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		if (IsVowel(Text[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

void PrintCountVowelsInString(int Result)
{
	cout << "\nNumber of vowels = " << Result << endl;
}



int main()
{
	string UserString = ReadString();

	PrintCountVowelsInString(CountVowelsInString(UserString));
}