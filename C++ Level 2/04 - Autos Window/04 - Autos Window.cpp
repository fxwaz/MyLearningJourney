#include <iostream>
using namespace std;



int main()
{

    // <<<< I started debugging from here 

    int Grades[5] = { 80, 90, 100, 70, 60 };

    int Sum = 0;

    for (int i = 0; i < 5; i++)
    {
        Sum = Grades[i];      // I found that the Sum variable was overwritten in every iteration which caused a logical error
        // Sum = Sum + Grades[i]
    }

    float Average = float(Sum) / 5;

    cout << "Average = " << Average << endl;


    // I can use more than one breakpoint to skip directly between different parts of the program

    // Autos Window automatically shows the variables related to the current line while debugging 
}