#include <iostream>
using namespace std;



void FillTwoDimArray(int Mult[10][10])
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Mult[i][j] = (i + 1) * (j + 1);
		}
	}
}

void PrintTwoDimArray(int Mult[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%0*d ", 2, Mult[i][j]);
		}

		cout << endl;
	}
}



int main()
{

	int Mult[10][10];

	FillTwoDimArray(Mult);

	PrintTwoDimArray(Mult);

}

/*
	// int x[rows][coulmns]
	int x[3][4] =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};




	for (int i = 0; i < 3; i++)
	{
		cout << "{ ";

		for (int j = 0; j < 4; j++)
		{
			cout << x[i][j];

			if (j < 3)
				cout << ", ";
		}

		cout << " }";

		cout << endl;
	}
*/