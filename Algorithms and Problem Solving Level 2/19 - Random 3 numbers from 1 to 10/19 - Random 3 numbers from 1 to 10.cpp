// Write a program to print a random numbers from 1 To 10.
#include <iostream>
using namespace std;


int RandomNumber(int From, int To)
{
                          
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;

}



int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 10) << endl;
}
