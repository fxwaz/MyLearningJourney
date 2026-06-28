// Write a program to print all words from AAA to ZZZ
#include <iostream>
using namespace std;


void PrintWords()
{
	for (int i = 65; i <= 90; i++)
	{

		for (int j = 65; j <= 90; j++)
		{
	

			for (int x = 65; x <= 90; x++)
			{
				cout << char(i) << char(j) << char(x) << endl;
			}


		}
		
		
	}
}

int main()
{
	PrintWords();
}
