// Write a program to check if the matrix is Sparse or not.
#include <iostream>
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
		for (int x = 0; x < cols; x++)
		{
			Matrix[i][x] = RandomNumber(0, 10);
		}
	}

}

int CountNumberInMatrix(int Matrix[3][3], int UserNumber, int rows, int cols)
{
	int Count = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (Matrix[i][x] == UserNumber)
				Count++;
		}
	}

	return Count;
}

bool IsMatrixSparse(int Matrix[3][3], int rows, int cols)
{
	int HowManyZero = CountNumberInMatrix(Matrix, 0, rows, cols);
	int HalfMatrix = (rows * cols) / 2;

	return (HowManyZero > HalfMatrix);
}

void PrintIsMatrixSparse(bool result)
{
	if (result)
		cout << "\nYes: It's a Sparse Matrix!\n";
	else
		cout << "\nNo: It's not a Sparse Matrix!\n";
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

	int Matrix[3][3] =
	{
		{ 5, 0, 0},
		{ 0, 5, 5},
		{ 0, 0, 5}
	};


	cout << "Matrix : \n";
	//FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	
	PrintIsMatrixSparse(IsMatrixSparse(Matrix, 3, 3));

	system("pause>0");
}