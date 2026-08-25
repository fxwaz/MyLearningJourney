// Write a program to fill a 3x3 matrix with ordered numbers and print it, then transpose matrix and print it.
#include <iostream>
#include <iomanip>
using namespace std;



void FillMatrixWithOrderedNumbers(int Matrix[3][3], int rows, int cols)
{
	int Count = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			Matrix[i][x] = Count;
			Count++;
		}
	}
}

void TransposeMatrix(int Matrix[3][3], int NewMatrix[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			NewMatrix[x][i] = Matrix[i][x];
		}
	}
}

void PrintMatrix(int Matrix[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			cout << left << setw(3) << Matrix[i][x] << "	";
		}

		cout << endl;
	}
}



int main()
{
	int Matrix[3][3];
	int NewMatrix[3][3];

	FillMatrixWithOrderedNumbers(Matrix, 3, 3);

	cout << "The following is a 3x3 ordered matrix : \n";
	PrintMatrix(Matrix, 3, 3);


	cout << "\nThe following is the transposed matrix : \n";
	TransposeMatrix(Matrix, NewMatrix, 3, 3);
	PrintMatrix(NewMatrix, 3, 3);
}