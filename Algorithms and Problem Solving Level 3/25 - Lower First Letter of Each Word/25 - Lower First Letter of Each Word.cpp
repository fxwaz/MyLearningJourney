// Write a program to read a string then lowercase the first letter of each word in that string.
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

string LowerFirstLetterOfEachWord(string Type)
{
	bool IsFirstLetter = true;

	for (int i = 0; i < Type.length(); i++)
	{
		if (Type[i] != ' ' && IsFirstLetter)
		{
			Type[i] = tolower(Type[i]);
		}

		IsFirstLetter = (Type[i] == ' ') ? true : false;
	}

	return Type;
}


int main()
{
	string UserType = ReadString();

	cout << "\nString after conversion : \n";
	UserType = LowerFirstLetterOfEachWord(UserType);

	cout << UserType << endl;

}