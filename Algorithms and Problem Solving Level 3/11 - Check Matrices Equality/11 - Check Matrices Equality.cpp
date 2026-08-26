// Write a program to compare two matrices and check if they are equal or not.
#include <iostream>
#include <ctime>
#include <iomanip>
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
			Matrix[i][y] = RandomNumber(1, 10);
		}
	}
}

int SumMatrix(int Matrix[3][3], int rows, int cols)
{
	int SumBox = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			SumBox = SumBox + Matrix[i][y];
		}
	}

	return SumBox;
}

bool IsMatricesEquals(int Matrix1[3][3], int Matrix2[3][3], int rows, int cols)
{
	int FirstResult = SumMatrix(Matrix1, rows, cols);
	int SecondResult = SumMatrix(Matrix2, rows, cols);

	return (FirstResult == SecondResult);
}

void PrintIsMatricesEqualsResult(bool result)
{
	if (result)
		cout << "\nYes : Matrices are Equals !" << endl;
	else
		cout << "\nNo : Matrices are not Equals !" << endl;
}


void PrintMatrix(int Matrix[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			printf("%0*d	", 2, Matrix[i][y]);
		}

		cout << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	int Matrix2[3][3];


	cout << "Matrix 1 :\n";
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix 2 :\n";
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);

	PrintIsMatricesEqualsResult(IsMatricesEquals(Matrix1, Matrix2, 3, 3));

}