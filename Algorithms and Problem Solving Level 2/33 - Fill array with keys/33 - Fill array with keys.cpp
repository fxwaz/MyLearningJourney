// Write a program to read how many keys to generate and fill them in array then print them on the screen.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType { CapitalLetter = 1, SmallLetter, SpecialChar, Digit };

int ReadNumberBetween(string Message, int From, int To)
{
	int UserNumber;

	do
	{
		cout << Message;
		cin >> UserNumber;

		if (UserNumber < From || UserNumber > To)
			cout << "You have to enter a number between " << From << " and " << To << ".\n\n";

	} while (UserNumber < From || UserNumber > To);

	return UserNumber;
}

int RandomNumber(int From, int To)
{
	int Randomnumber = rand() % (To - From + 1) + From;

	return Randomnumber;
}

char GetRandomCharacter(enCharType CharType)
{

	switch (CharType)
	{
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));

	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));

	case enCharType::SpecialChar:
		return char(RandomNumber(33, 47));

	case enCharType::Digit:
		return char(RandomNumber(48, 57));

	}

}

string GenerateWord(enCharType CharType, int Length)
{
	string Word = "";

	for (int i = 1; i <= Length; i++)
	{
		Word = Word + GetRandomCharacter(CharType);
	}

	return Word;
}

string GenerateKey()
{
	string Key = "";

	for (int i = 1; i <= 4; i++)
	{
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

		if (i < 4)
			Key = Key + "-";
	}

	return Key;
}

void FillArrayWithKeys(string Array[], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = GenerateKey();
	}
}

void PrintStringArray(string Array[], int ArrayLength)
{
	cout << endl;

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Array [" << i << "] : " << Array[i] << endl;
	}

}


int main()
{
	srand((unsigned)time(NULL));

	string Keys[100];
	int ArrayLength = ReadNumberBetween("Please enter how many keys do u want to generate : ", 1, 100);


	FillArrayWithKeys(Keys, ArrayLength);
	PrintStringArray(Keys, ArrayLength);

}