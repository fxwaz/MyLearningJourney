// Write a program to check if the matrix is identity or not.
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
			Matrix[i][y] = RandomNumber(0, 1);
		}
	}
}

bool IsMatrixIdentity(int Matrix[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (i == y)
			{
				if (Matrix[i][y] != 1)
					return false;
			}
			else
			{
				if (Matrix[i][y] != 0)
					return false;
			}
		}
	}

	return true;

}

void PrintIsMatrixIdentity(bool result)
{
	if (result)
		cout << "\nYes : Matrix is identity !" << endl;
	else
		cout << "\nNo : Matrix is not identity !" << endl;
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

	int Matrix[3][3];


	cout << "Matrix :\n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	PrintIsMatrixIdentity(IsMatrixIdentity(Matrix, 3, 3));


	system("pause>0");
}