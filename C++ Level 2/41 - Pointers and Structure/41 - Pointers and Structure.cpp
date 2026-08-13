#include <iostream>
using namespace std;



struct stEmployee
{
	string Name;
	float Salary;
};


int main()
{
	stEmployee Employee;
	stEmployee *pointer;

	Employee.Name = "Fawaz Alzahrani";
	Employee.Salary = 25000;

	cout << Employee.Name << endl;
	cout << Employee.Salary << endl;

	pointer = &Employee;

	cout << "\nUsing Pointer:" << endl;
	cout << pointer << endl;
	cout << pointer->Name << endl;
	cout << pointer->Salary << endl;

}