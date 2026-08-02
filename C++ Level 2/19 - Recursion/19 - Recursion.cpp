// 19 - Recursion
#include <iostream>
using namespace std;


// From N to M
void PrintNumbers(int N, int M)
{

	if (N <= M)
	{
		cout << N << endl;
		PrintNumbers(N + 1, M);
	}
}

// From M to N
void PrintNumbers2(int M, int N)
{

	if (N <= M)
	{
		cout << M << endl;
		PrintNumbers2(M - 1, N);
	}

}

// Power N^P
int MyPower(int Number, int Power)
{

	if (Power == 0)
	{
		return 1;
	}
	else
	{
		return Number * MyPower(Number, Power - 1);
	}
	
	

}

int main()
{
	PrintNumbers(1, 6);
	cout << endl;
	PrintNumbers2(6, 1);
	cout << endl;
	cout << MyPower(2, 3) << endl;
}

