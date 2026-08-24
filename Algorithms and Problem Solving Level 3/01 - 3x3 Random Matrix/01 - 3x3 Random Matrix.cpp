// Write a program to fill a 3x3 matrix with random numbers.
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

void FillMatrixArrayWithRandomNumbers(int Array[3][3], int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < cols; x++)
		{
			Array[i][x] = RandomNumber(1, 100);
		}
	}

}

void PrintMatrixArray(int Matrix[3][3], int rows, int cols)
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
	
	FillMatrixArrayWithRandomNumbers(MatrixArray, 3, 3);

	cout << "The Following is a 3x3 Random Matrix : \n";
	PrintMatrixArray(MatrixArray, 3, 3);


	// Pause the program and wait for a key press without showing a message
	system("pause>0");
}