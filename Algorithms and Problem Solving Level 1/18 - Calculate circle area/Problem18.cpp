// Write a program to calculate circle area then print it on the screen
#include <iostream>
#include <cmath>
using namespace std;


float ReadRadius()
{
	float Radius;
	cout << "Please enter Radious : ";
	cin >> Radius;

	return Radius;
}

float CalculateCircleArea(float Radius)
{
	const float PI = 3.14159265358979323846;

	return PI * pow(Radius, 2);
}

void PrintResult(float result)
{
	cout << "\n Circle Area = " << result << endl;
}

int main()
{

	PrintResult(CalculateCircleArea(ReadRadius()));

}