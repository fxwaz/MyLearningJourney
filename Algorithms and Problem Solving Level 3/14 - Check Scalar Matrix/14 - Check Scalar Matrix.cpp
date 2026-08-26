// Write a program to check if the matrix is scalar or not.
#include <iostream>
using namespace std;



bool IsMatrixScalar(int Matrix[3][3], int rows, int cols)
{
	int DiagonalValue = Matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (i == y)
			{
				if (Matrix[i][y] != DiagonalValue)
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

void PrintIsMatrixScalar(bool result)
{
	if (result)
		cout << "\nYes : Matrix is scalar !" << endl;
	else
		cout << "\nNo : Matrix is not scalar !" << endl;
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

	int Matrix[3][3] =
	{
		{ 5, 0, 0},
		{ 0, 5, 0},
		{ 0, 0, 5}
	};


	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	PrintIsMatrixScalar(IsMatrixScalar(Matrix, 3, 3));


	system("pause>0");
}