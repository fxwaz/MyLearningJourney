// Write a program to fill a 3x3 matrix with random numbers, print it, then print the middle row and middle col
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
		for (int x = 0; x < cols; x++)
		{
			Matrix[i][x] = RandomNumber(1, 100);
		}
	}

}

void PrintMatrix(int Matrix[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			cout << left << setw(3) << Matrix[i][y] << "	";
		}

		cout << endl;
	}
}

void PrintMiddleRowOfMatrix(int Matrix[3][3], int rows, int cols)
{
	int MiddleRow = rows / 2;

	for (int i = 0; i < cols; i++)
	{
		printf("%0*d	", 2, Matrix[MiddleRow][i]);
	}

}

void PrintMiddleColOfMatrix(int Matrix[3][3], int rows, int cols)
{
	int MiddleCol = cols / 2;

	for (int i = 0; i < rows; i++)
	{
		printf("%0*d	", 2, Matrix[i][MiddleCol]);
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int MatrixArray[3][3];


	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(MatrixArray, 3, 3);
	PrintMatrix(MatrixArray, 3, 3);

	cout << "\nMiddle Row of Matrix 1 Is : \n";
	PrintMiddleRowOfMatrix(MatrixArray, 3, 3);

	cout << "\n\nMiddle Col of Matrix 1 Is : \n";
	PrintMiddleColOfMatrix(MatrixArray, 3, 3);

	// Pause the program and wait for a key press without showing a message
	system("pause>0");
}