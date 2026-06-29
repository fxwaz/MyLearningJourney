// Write a program to guess a 3-Letter password (all capital)
#include <iostream>
using namespace std;


string ReadPassword(string Message)
{
	string UserPass;

	do
	{
		cout << Message;
		cin >> UserPass;

		if (UserPass.length() != 3)
			cout << "You have to enter only 3 letters!" << endl;

	} while (UserPass.length() != 3);


	return UserPass;
}


void Guess3LetterPass(string UserPass)
{
	string word = "";
	int Counter = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int x = 65; x <= 90; x++)
			{
				Counter++;

				word = word + char(i);
				word = word + char(j);
				word = word + char(x);

				cout << "Trial " << "[" << Counter << "]" << " : " << word << endl;

				if (UserPass == word)
				{
					cout << "\nYour Password is : " << word << endl;
					cout << "Found after " << Counter << " Trial(s)" << endl;
					return;
				}

				word = "";
				

			}
		}
	}
}


int main()
{
	Guess3LetterPass(ReadPassword("Please enter a 3 letter password ((Only Capital)) : "));
}