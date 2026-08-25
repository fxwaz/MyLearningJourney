// Write a program to fill a 3x3 matrix with random numbers, then write a function to sum all numbers in this matrix and print it.
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
			Matrix[i][x] = RandomNumber(1, 10);
		}
	}

}

int SumOfMatrix(int Matrix[3][3], int rows, int cols)
{
	int SumBox = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			SumBox = SumBox + Matrix[i][j];
		}
	}

	return SumBox;
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

	cout << "Matrix 1 : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	cout << "\nSum of Matrix 1 is : " << SumOfMatrix(Matrix, 3, 3);
	

	system("pause>0");
}
