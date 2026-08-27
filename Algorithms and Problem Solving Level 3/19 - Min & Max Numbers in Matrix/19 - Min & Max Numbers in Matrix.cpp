// Write a program to print the Minimum and Maximum Numbers in Matrix.
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;



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
		for (int y = 0; y < cols; y++)
		{
			Matrix[i][y] = RandomNumber(1, 100);
		}
	}
}

int GetMaxNumberInMatrix(int Matrix[3][3], int rows, int cols)
{
	int MaxNumber = Matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (Matrix[i][y] > MaxNumber)
				MaxNumber = Matrix[i][y];
		}

	}

	return MaxNumber;
}

int GetMinNumberInMatrix(int Matrix[3][3], int rows, int cols)
{
	int MinNumber = Matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (Matrix[i][y] < MinNumber)
				MinNumber = Matrix[i][y];
		}

	}

	return MinNumber;
}

void PrintMatrix(int Matrix[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			cout << left << setw(2) << Matrix[i][y] << "	";
		}

		cout << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	cout << "Matrix :\n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMax Number is : \n";
	cout << GetMaxNumberInMatrix(Matrix, 3, 3) << endl;

	cout << "\nMin Number is : \n";
	cout << GetMinNumberInMatrix(Matrix, 3, 3) << endl;
}