// Write a program to read a string then count small/capital letters in that string.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


enum enWhatToCount { CapitalLetters = 1, SmallLetters = 2 , All};


string ReadString()
{
	string UserString;

	cout << "Please enter your string : ";
	getline(cin, UserString);

	return UserString;
}

int CountLetters(string Text, enWhatToCount CountType = enWhatToCount::All)
{
	int Count = 0;


	if (CountType == enWhatToCount::All)
		return Text.length();


	for (int i = 0; i < Text.length(); i++)
	{

		if (CountType == enWhatToCount::CapitalLetters && isupper(Text[i]))
		{
			Count++;
		}

		if (CountType == enWhatToCount::SmallLetters && islower(Text[i]))
		{
			Count++;
		}

	}


	return Count;

}

int CountCapitalLettersInString(string Text)
{
	int CapitalLetters = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		if (isupper(Text[i]))
		{
			CapitalLetters++;
		}

	}

	return CapitalLetters;
}

int CountSmallLettersInString(string Text)
{
	int SmallLetters = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		if (islower(Text[i]))
		{
			SmallLetters++;
		}

	}

	return SmallLetters;
}



int main()
{
	string MyString = ReadString();

	cout << "\nString Length = ";
	cout << MyString.length();

	cout << "\nCapital Letters Count = ";
	cout << CountCapitalLettersInString(MyString);

	cout << "\nSmall Letters Count = ";
	cout << CountSmallLettersInString(MyString);

	cout << "\n\n---- Another way ----\n";

	cout << "\nString Length = ";
	cout << CountLetters(MyString);

	cout << "\nCapital Letters Count = ";
	cout << CountLetters(MyString, enWhatToCount::CapitalLetters);
	
	cout << "\nSmall Letters Count = ";
	cout << CountLetters(MyString, enWhatToCount::SmallLetters);


	cout << endl;
}