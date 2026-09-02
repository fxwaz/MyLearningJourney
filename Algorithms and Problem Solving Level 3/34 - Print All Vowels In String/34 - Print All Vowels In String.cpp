// Write a program to read a string then print all vowels in that string (Vowels are : a, e, i, o, u)
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

void PrintVowelsInString(string Text)
{
	cout << "\nVowels in string are : ";

	for (int i = 0; i < Text.length(); i++)
	{
		if (IsVowel(Text[i]))
		{
			cout << Text[i] << "   ";
		}
	}

	cout << endl;

}



int main()
{
	string UserString = ReadString();

	PrintVowelsInString(UserString);
}