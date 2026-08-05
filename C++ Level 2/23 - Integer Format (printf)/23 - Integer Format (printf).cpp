#include <iostream>
using namespace std;



int main()
{
	int Number = 1;
	int Pages = 10;

	// Print string and int variable
	printf("The value of Number variable is : %d \n", Number);
	printf("The number of page is %d from %d pages \n", Number, Pages);

	// Print the number with a minimum width
	// Zeros are added before the number if needed like 01 or 001 or 0001
	printf("Test 3 number of digits in this string : %0*d \n", 3, Number);
	printf("Test 5 number of digits in this string : %0*d \n", 5, Number);
	printf("Test 8 number of digits in this string : %0*d \n", 8, Number);

	printf("10 + 20 Equal %d \n", 10 + 20);

	int Number1 = 50;
	int Number2 = 100;

	printf("The Result of %d + %d = %d \n", Number1, Number2, Number1 + Number2);
}														   