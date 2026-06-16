// Write a program to calculate circle area inscribed in a square, then print it on the screen.
#include <iostream>
#include <cmath>
using namespace std;


float ReadSquareSide()
{
	float Side;

	cout << "Please enter square side : ";
	cin >> Side;

	return Side;
}

float CalculateCircleArea(float Side)
{
	const float PI = 3.14159265358979323846;

	return (PI * pow(Side, 2)) / 4;
}

void PrintResult(float Result)
{
	cout << "Circle area = " << Result << endl;
}

int main()
{
	PrintResult(CalculateCircleArea(ReadSquareSide()));
}