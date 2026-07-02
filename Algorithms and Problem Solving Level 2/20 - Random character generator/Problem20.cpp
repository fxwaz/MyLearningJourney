// Write a program to print a random capital letter, small letter, special character, and digit in order.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enCharType { CapitalLetter = 1, SmallLetter, SpecialChar, Digit };


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

void PrintResult(char Chartype)
{
	cout << Chartype << endl;
}


int main()
{
	srand((unsigned)time(NULL));

	PrintResult(GetRandomCharacter(enCharType::CapitalLetter));
	PrintResult(GetRandomCharacter(enCharType::SmallLetter));
	PrintResult(GetRandomCharacter(enCharType::SpecialChar));
	PrintResult(GetRandomCharacter(enCharType::Digit));

}