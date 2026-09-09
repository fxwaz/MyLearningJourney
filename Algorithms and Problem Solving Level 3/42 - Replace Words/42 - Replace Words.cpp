// Write a program to replace words in string.
#include <iostream>
#include <string>
using namespace std;



string ReadString(string Message)
{
	string UserString;

	cout << Message;
	getline(cin, UserString);

	return UserString;
}

string ReplaceWordInString(string Text, string Word, string NewWord)
{
	int WordPosition = Text.find(Word);

	while (WordPosition != string::npos)
	{
		Text.replace(WordPosition, Word.length(), NewWord);
	
		WordPosition = Text.find(Word, WordPosition + NewWord.length());
	}

	return Text;
}



int main()
{
	string UserString = ReadString("Please enter your string : ");

	cout << "\nOriginal String : \n";
	cout << UserString << endl;

	string UserWord = ReadString("\nPlease enter the word you want to change : ");
	string UserNewWord = ReadString("Please enter the new word : ");

	cout << "\nString After Replace : \n";
	cout << ReplaceWordInString(UserString, UserWord, UserNewWord) << endl;
}

