// Write a program to calculate rectangle area through diagonal and side area of rectangle and print it on the screen
#include <iostream>
#include <cmath>
using namespace std;


void ReadNumbers(float& side, float& diagonal)
{
	cout << "Please enter rectangle side : ";
	cin >> side;

	cout << "Please enter rectangle diagonal : ";
	cin >> diagonal;
}

float CalculateRectangleAreaBySideAndDiagonal(float side, float diagonal)
{
	return side * sqrt(pow(diagonal, 2) - pow(side, 2));
}

void PrintResult(float result)
{
	cout << "Rectangle Area = " << result << endl;
}

int main()
{
	float side, diagonal;

	ReadNumbers(side, diagonal);
	PrintResult(CalculateRectangleAreaBySideAndDiagonal(side, diagonal));
}