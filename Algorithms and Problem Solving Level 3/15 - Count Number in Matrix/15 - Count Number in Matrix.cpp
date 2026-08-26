// Write a program to count given number in matrix.
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


int ReadNumber(string Message)
{
	int UserNumber = 0;

	cout << Message;
	cin >> UserNumber;

	return UserNumber;
}

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
	int UserNumber = 0;

	cout << "Matrix : \n";
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	PrintMatrix(Matrix, 3, 3);

	UserNumber = ReadNumber("\nEnter the number to count in Matrix : ");

	cout << "Number " << UserNumber << " count in Matrix is : ";
	cout << CountNumberInMatrix(Matrix, UserNumber, 3, 3) << endl;

	system("pause>0");
}