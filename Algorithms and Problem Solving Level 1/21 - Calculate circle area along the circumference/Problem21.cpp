// Write a program to calculate circle area along the circumference, then print it on the screen.
#include <iostream>
#include <cmath>
using namespace std;


float ReadCircumference()
{
	float Circumference;

	cout << "Please enter circle circumference : ";
	cin >> Circumference;

	return Circumference;
}

float CircleAreaByCircumference(float Circumference)
{
	const float PI = 3.14159265358979323846;

	return pow(Circumference, 2) / (4 * PI);
}

void PrintResult(float CircleArea)
{
	cout << "Circle area = " << CircleArea << endl;
}

int main()
{
	

	PrintResult(CircleAreaByCircumference(ReadCircumference()));


}