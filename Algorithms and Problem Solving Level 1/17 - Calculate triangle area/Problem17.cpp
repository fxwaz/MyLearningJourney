// Write a program to calculate triangle area then print it on the screen
#include <iostream>
using namespace std;

void ReadNumbers(float& base, float& height)
{

	cout << "Please enter triangle base : ";
	cin >> base;

	cout << "Please enter triangle height : ";
	cin >> height;

}

float CalculateTriangleArea(float base, float height)
{
	return 0.5 * (base * height);
}

void PrintResult(float result)
{
	cout << "\n Triangle Area = " << result << endl;
}

int main()
{
	float base, height;

	ReadNumbers(base, height);
	PrintResult(CalculateTriangleArea(base, height));

}