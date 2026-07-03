// Write a program to read how many keys to generate and print them on the screen.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType { CapitalLetter = 1, SmallLetter, SpecialChar, Digit };

int ReadPositiveNumber(string Message)
{
	int UserNumber;

	do
	{
		cout << Message;
		cin >> UserNumber;


	} while (UserNumber <= 0);

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

void GenerateKeys(int NumberOfKeys)
{
	
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << endl;
		cout << "Key [" << i << "] " << " : " << GenerateKey();
	}

	cout << endl;
	
}


int main()
{
	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("Please enter how many keys u want to generate : "));
}