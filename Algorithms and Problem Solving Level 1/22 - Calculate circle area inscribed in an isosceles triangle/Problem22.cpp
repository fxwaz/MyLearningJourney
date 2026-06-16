// Write a program to calculate circle area inscribed in an isosceles triangle, then print it on the screen
#include <iostream>
#include <cmath>
using namespace std;


void ReadTriangleData(float& side, float& base)
{
	cout << "Please enter triangle side : ";
	cin >> side;

	cout << "Please enter triangle base : ";
	cin >> base;
}

float CalculateCircleArea(float side, float base)
{
	const float PI = 3.14159265358979323846;

	return PI * (pow(side, 2) / 4) * ((2 * side - base) / (2 * side + base));
}

void PrintResult(float result)
{
	cout << "Circle area = " << result << endl;
}

int main()
{
	float side, base;

	ReadTriangleData(side, base);
	PrintResult(CalculateCircleArea(side, base));
}