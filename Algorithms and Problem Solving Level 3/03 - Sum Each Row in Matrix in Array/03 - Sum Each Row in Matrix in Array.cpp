// Write a program to fill a 3x3 matrix with random numbers, then sum each row in separate array and print the results.
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

int RowSum(int Array[3][3], int rownumber, int cols)
{

	int SumBox = 0;

	for (int i = 0; i < cols; i++)
	{
		SumBox = SumBox + Array[rownumber][i];
	}

	return SumBox;

}

void FillArrayWithRowSums(int MatrixArray[3][3],int SpearateArray[3], int rows, int cols)
{
	
	for (int i = 0; i < rows; i++)
	{
		SpearateArray[i] = RowSum(MatrixArray, i, cols);
	}
}

void PrintRowSums(int SeparateArray[], int Length)
{
	cout << "\nThe Following are the Sum of Each Row in the Matrix : \n";

	for (int i = 0; i < Length; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << SeparateArray[i] << endl;
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



int main()
{
	srand((unsigned)time(NULL));

	int MatrixArray[3][3];
	int NewArray[3];

	FillMatrixWithRandomNumbers(MatrixArray, 3, 3);

	cout << "The Following is a 3x3 Random Matrix : \n";
	PrintMatrix(MatrixArray, 3, 3);


	FillArrayWithRowSums(MatrixArray, NewArray, 3, 3);
	PrintRowSums(NewArray, 3);

	// Pause the program and wait for a key press without showing a message
	system("pause>0");
}