// Write a program to check if a given number exists in matrix or not.
#include <iostream>
#include <ctime>
using namespace std;



int ReadNumber(string Message)
{
	int UserNumber = 0;

	cout << Message;
	cin >> UserNumber;

	return UserNumber;
}

int RandomNumber(int From, int To)
{
	int RandomNumber;

	RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			Matrix[i][x] = RandomNumber(1, 10);
		}
	}

}

bool IsNumberInMatrix(int Matrix[3][3], int UserNumber, int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (Matrix[i][x] == UserNumber)
				return true;
		}
	}

	return false;
}

void PrintIsNumberInMatrix(bool result)
{
	if (result)
		cout << "\nYes it is there.\n";
	else
		cout << "No it is not there.\n";
}

void PrintMatrix(int Matrix[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			printf("%0*d	", 0, Matrix[i][y]);
		}

		cout << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int UserNumber = 0;

	cout << "Matrix : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	UserNumber = ReadNumber("\nPlease enter a number to look for in matrix : ");

	PrintIsNumberInMatrix(IsNumberInMatrix(Matrix, UserNumber, 3, 3));

	system("pause>0");
}