// Write a program to read a character then check if it is a vowel or not (Vowels are : a, e, i, o, u).
#include <iostream>
#include <cctype>
using namespace std;



char ReadChar()
{
	char UserChar;

	cout << "Please enter your char : ";
	cin >> UserChar;

	return UserChar;
}

bool IsVowel(char Letter)
{
	char ConvertToSmall = tolower(Letter);

	return (ConvertToSmall == 'a' || ConvertToSmall == 'e' || ConvertToSmall == 'i' || ConvertToSmall == 'o' || ConvertToSmall == 'u');

}

void PrintIsVowel(char Letter)
{
	if (IsVowel(Letter))
	{
		cout << "\nYes, Letter '" << Letter << "' is vowel.\n";
	}
	else
	{
		cout << "\nNo, Letter '" << Letter << "' is not vowel.\n";
	}
}



int main()
{
	char UserChar = ReadChar();

	PrintIsVowel(UserChar);
}