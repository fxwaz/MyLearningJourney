// Write a program to fill a 3x3 matrix with random numbers, then sum each Col in another array and print them.
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

void FillMatrixWithRandomNumbers(int Array[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			Array[i][x] = RandomNumber(1, 100);
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

int ColSum(int Matrix[3][3], int rows, int ColNumber)
{
	int SumBox = 0;

	for (int i = 0; i < rows; i++)
	{
		SumBox += Matrix[i][ColNumber];
	}

	return SumBox;
}

void FillArrayWithColSums(int Matrix[3][3], int Array[], int rows, int cols)
{
	for (int i = 0; i < cols; i++) 
	{
		Array[i] = ColSum(Matrix, rows, i);
	}
}

void PrintColSums(int Array[], int Length)
{
	cout << "\nThe Following are the sum of each col in the matrix : \n";

	for (int i = 0; i < Length; i++)
	{
		cout << "Col " << i + 1 << " Sum = " << Array[i] << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int MatrixArray[3][3];
	int NewArray[3];

	FillMatrixWithRandomNumbers(MatrixArray, 3, 3);

	cout << "The Following is a 3x3 Random Matrix : \n";
	PrintMatrix(MatrixArray, 3, 3);


	FillArrayWithColSums(MatrixArray, NewArray, 3, 3);
	PrintColSums(NewArray, 3);

	// Pause the program and wait for a key press without showing a message
	system("pause>0");
}