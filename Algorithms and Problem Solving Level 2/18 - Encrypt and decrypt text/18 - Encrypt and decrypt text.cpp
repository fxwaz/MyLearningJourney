// write a program to read a text and encrypt it, decrypt it.
#include <iostream>
#include <string>
using namespace std;


string ReadText(string Message)
{
	string UserText; 

	cout << Message;
	getline(cin, UserText);

	return UserText;
}

string EncryptText(string Text)
{
	int TextLength = Text.length() - 1;
	short EncryptionKey = 10;

	for (int i = 0; i <= TextLength; i++)
	{
		Text[i] = Text[i] + EncryptionKey;
	}

	return Text;
}



string DecryptText(string Text)
{
	int TextLength = Text.length() - 1;
	short EncryptionKey = 10;

	for (int i = 0; i <= TextLength; i++)
	{
		Text[i] = Text[i] - EncryptionKey;
	}

	return Text;
}

void PrintResult(string message, string result)
{
	cout << message << result << endl;
}

int main()
{
	string Text = ReadText("Please enter a text : ");
	string TextAfterEncryption = EncryptText(Text);
	string TextAfterDecryption = DecryptText(TextAfterEncryption);

	PrintResult("\nOriginal Text : ", Text);
	PrintResult("Text after Encryption : ", TextAfterEncryption);
	PrintResult("Text after Decryption : ", TextAfterDecryption);
}
