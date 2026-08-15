#include <iostream>
using namespace std;



int main()
{
	int NumberOfStudents = 0;
	cout << "Enter total number of students : ";
	cin >> NumberOfStudents;

	// Dynamically allocate an array and store the address of the first element in the pointer
	int* StudentGrades = new int[NumberOfStudents];



	cout << "\nEnter grades of students : " << endl;

	for (int i = 0; i < NumberOfStudents; i++)
	{
		cout << "Student " << i + 1 << " : ";
		// Dereference the pointer to store the grade in the current array element
		cin >> *(StudentGrades + i);
	}



	cout << "\nGrades of students : " << endl;

	for (int i = 0; i < NumberOfStudents; i++)
	{
		cout << "Student " << i + 1 << " : ";
		cout << *(StudentGrades + i) << endl;
	}

	// Deallocate the dynamically allocated array
	delete[] StudentGrades;
}