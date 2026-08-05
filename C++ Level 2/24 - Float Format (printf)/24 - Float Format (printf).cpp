#include <iostream>
using namespace std;



int main()
{
	float PI = 3.14159265;


	// Precision Specification
	// %.1f prints the number with 1 digit after the decimal point
	// Example: 3.14159 with %.1f will be 3.1
	printf("Precision specification of %.1f \n", PI);

	// %.*f does the same but the precision is taken from the next argument
	printf("Precision specification of %.*f \n", 2, PI);
	printf("Precision specification of %.*f \n", 3, PI);
	printf("Precision specification of %.*f \n", 4, PI);


	float A = 7.0;
	float B = 9.50;
	double C = 15.34;

	
	printf("\nThe float division is : %.3f / %.3f = %.3f \n", A, B, A / B);

	// Same precision specifier works with both float and double
	printf("\nThe double value is : %.3f \n", C);
	printf("The double value is : %.4f \n", C);
}
