// Write a program that calculates the area of a rectangle and prints it on the screen.
#include <iostream>
using namespace std;


void ReadLengthAndWidth(float& Length, float& Width)
{
	cout << "Please enter the Length : ";
	cin >> Length;

	cout << "Please enter the Width : ";
	cin >> Width;
}

float CalculateArea(float Length, float Width)
{
	return Length * Width;
}

void PrintResult(float Area)
{
	cout << "\n Rectangle Area = " << Area << endl;
}

int main()
{

	float Length, Width;

	ReadLengthAndWidth(Length, Width);
	PrintResult(CalculateArea(Length, Width));

}