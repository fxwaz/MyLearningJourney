// Write a program to ask user to enter as many Employees as he wants, each time an Employee entered add it to your vector and ask the user if he wants to add more Employees until he says No, then print all vector elements on the screen.
#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary = 0;
};


void ReadEmployees(vector <stEmployee> &vEmployee)
{
    stEmployee tempEmployee;
    char Continue = 'Y';
    int Count = 1;

    while (Continue == 'Y' || Continue == 'y')
    {
        cout << "Employee " << "[" << Count << "]" << endl;

        cout << "\nEnter First Name : ";
        getline(cin, tempEmployee.FirstName);

        cout << "Enter Last Name : ";
        getline(cin, tempEmployee.LastName);

        cout << "Enter Salary : ";
        cin >> tempEmployee.Salary;

        vEmployee.push_back(tempEmployee);

        cout << "\nDo u want to continue ? [Y] Yes, [N] No : ";
        cin >> Continue;
        cout << endl;

        cin.ignore();

        Count++;
    }
}

void PrintEmployees(vector <stEmployee>& vEmployee)
{
    cout << "Your Employee's Information's : \n\n";

    int Count = 1;

    for (stEmployee &Employee : vEmployee)
    {
        cout << "Employe [" << Count << "]\n";
        cout << "First name : " << Employee.FirstName << endl;
        cout << "Last name : " << Employee.LastName << endl;
        cout << "Salary : " << Employee.Salary << endl;

        cout << endl;

        Count++;
    }
}


int main()
{
    vector <stEmployee> vEmployee;

    ReadEmployees(vEmployee);
    PrintEmployees(vEmployee);

}




/*
* 
vector <stEmployee> vEmployee;
    stEmployee tempEmployee;


    tempEmployee.FirstName = "Fawaz";
    tempEmployee.LastName = "Alzahrani";
    tempEmployee.Salary = 10000;
    vEmployee.push_back(tempEmployee);

    tempEmployee.FirstName = "Fawaz";
    tempEmployee.LastName = "Alzahrani";
    tempEmployee.Salary = 15000;
    vEmployee.push_back(tempEmployee);

    tempEmployee.FirstName = "Fawaz";
    tempEmployee.LastName = "Alzahrani";
    tempEmployee.Salary = 25000;
    vEmployee.push_back(tempEmployee);

    cout << "Employees Vector : " << endl;

    for (stEmployee &Employee : vEmployee)
    {
        cout << "\nFirst Name : " << Employee.FirstName << endl;
        cout << "Last Name : " << Employee.LastName << endl;
        cout << "Salary : " << Employee.Salary << endl;
    }
*/