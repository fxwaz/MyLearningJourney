// Write a program to check if the matrix is Palindrome or not.
#include <iostream>
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
			Matrix[i][y] = RandomNumber(1, 100);
		}
	}
}

bool IsPalindromeMatrix(int Matrix[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols / 2; y++)
		{
			if (Matrix[i][y] != Matrix[i][cols - 1 - y])
				return false;
		}
	}

	return true;
}

void PrintIsPalindromeMatrix(bool result)
{
	if (result)
		cout << "\nYes : The Matrix Is Palindrome. \n";
	else
		cout << "\nNo : The Matrix Is Not Palindrome. \n";
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

	int Matrix[3][3] =
	{
		{ 1 , 5 , 1},
		{ 5 , 5 , 5},
		{ 1 , 7 , 1}
	};

	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	PrintIsPalindromeMatrix(IsPalindromeMatrix(Matrix, 3, 3));
}