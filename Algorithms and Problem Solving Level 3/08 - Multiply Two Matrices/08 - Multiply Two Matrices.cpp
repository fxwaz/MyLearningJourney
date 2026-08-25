// Write a program to fill two 3x3 matrices with random numbers then multiply them into a third matrix and print it.
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;



int RandomNumbers(int From, int To)
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
			Matrix[i][y] = RandomNumbers(1, 10);
		}
	}
}

void Multiply2Matrices(int Matrix1[3][3], int Matrix2[3][3], int ResultMatrix[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			ResultMatrix[i][x] = Matrix1[i][x] * Matrix2[i][x];
		}
	}
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
	int Matrix[3][3];
	int Matrix2[3][3];
	int MultMatrix[3][3];

	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMatrix 2 : \n";
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	PrintMatrix(Matrix2, 3, 3);


	cout << "\nResults : \n";
	Multiply2Matrices(Matrix, Matrix2, MultMatrix, 3, 3);
	PrintMatrix(MultMatrix, 3, 3);
}
