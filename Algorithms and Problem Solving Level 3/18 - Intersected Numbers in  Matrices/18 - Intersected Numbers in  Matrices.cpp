// Write a program to print the intersected numbers in two given matrices.
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
			Matrix[i][y] = RandomNumber(1, 20);
		}
	}
}

bool IsNumberInMatrix(int Matrix[3][3], int numbertosearch, int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (Matrix[i][y] == numbertosearch)
				return true;
		}

	}

	return false;
}

void PrintIntersectedInMatrices(int Matrix1[3][3], int Matrix2[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{

			if (IsNumberInMatrix(Matrix2, Matrix1[i][y], rows, cols))
				cout << left << setw(3) << Matrix1[i][y] << "  ";

		}

		
	}

	cout << endl;

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

	int Matrix1[3][3];
	int Matrix2[3][3];

	cout << "Matrix 1 :\n";
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix 2 :\n";
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are : \n";
	PrintIntersectedInMatrices(Matrix1, Matrix2, 3, 3);
}