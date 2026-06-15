// Write a program to calculate circle area through diameter, then print it on the screen.
#include <iostream>
#include <cmath>
using namespace std;


float ReadDiameter()
{
	float Diameter;

	cout << "Please enter Diameter : ";
	cin >> Diameter;

	return Diameter;
}

float CalculateCircleArea(float Diameter)
{
	const float PI = 3.14159265358979323846;

	return (PI * pow(Diameter, 2)) / 4;
}

void PrintResult(float AreaResult)
{
	cout << "\n Circle area = " << AreaResult << endl;
}

int main()
{

	PrintResult(CalculateCircleArea(ReadDiameter()));

}

