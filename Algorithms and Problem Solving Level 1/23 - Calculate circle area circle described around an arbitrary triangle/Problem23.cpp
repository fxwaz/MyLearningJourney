// Write a program to calculate circle area circle described around an arbitrary triangle, then print it on the screen.
#include <iostream>
#include <cmath>
using namespace std;


void ReadNumbers(float& a, float& b, float& c)
{
	cout << "Please enter triangle side a : ";
	cin >> a;

	cout << "Please enter triangle base b : ";
	cin >> b;

	cout << "Please enter triangle side c : ";
	cin >> c;
}

float CalculateCircleAreaByTriangle(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	const float PI = 3.14159265358979323846;
	float Area = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));

	return PI * pow(Area, 2);

}

void PrintResult(float result)
{
	cout << "Circle area = " << result << endl;
}

int main()
{
	float a, b, c;

	ReadNumbers(a, b, c);
	PrintResult(CalculateCircleAreaByTriangle(a, b, c));
}