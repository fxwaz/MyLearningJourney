#include <iostream>
#include <vector>
using namespace std;


int main()
{

    // Iterator is an object used to move through the elements of a Vector and access them one by one
	vector <int> Numbers = { 10, 20, 30, 40, 50 };

	vector <int>::iterator iter;

	for (iter = Numbers.begin(); iter != Numbers.end(); iter++)
	{
		cout << *iter << endl;
	}



    /*

        Iterator is an object used to move through the elements of a Vector and access them one by one
        
     
        
                begin()                              end()
                   ↓                                   ↓
                ┌──────┬──────┬──────┬──────┬──────┐
  Vector ->     │  10  │  20  │  30  │  40  │  50  │
                └──────┴──────┴──────┴──────┴──────┘
                   ↑
                  iter
        
        
        Numbers.begin()
        Represents the position of the first element in the Vector

        iter = Numbers.begin()
        Makes iter start at the first element
        
                ┌──────┬──────┬──────┬──────┬──────┐
                │  10  │  20  │  30  │  40  │  50  │
                └──────┴──────┴──────┴──────┴──────┘
                   ↑
                  iter
        
        *iter = 10
        
        
        iter++
        Moves the iterator to the next element
        
                ┌──────┬──────┬──────┬──────┬──────┐
                │  10  │  20  │  30  │  40  │  50  │
                └──────┴──────┴──────┴──────┴──────┘
                          ↑
                         iter
        
        *iter = 20
        
        
        Each iter++ moves to the next element:
        
                ┌──────┬──────┬──────┬──────┬──────┐
                │  10  │  20  │  30  │  40  │  50  │
                └──────┴──────┴──────┴──────┴──────┘
                   ↑      ↑      ↑      ↑      ↑
                  1st    2nd    3rd    4th    5th
        
        
        Numbers.end()
        Marks the position after the last element in the Vector
        It is used to know when the iterator should stop
        
                ┌──────┬──────┬──────┬──────┬──────┐
                │  10  │  20  │  30  │  40  │  50  │
                └──────┴──────┴──────┴──────┴──────┘
                                                     ↑
                                                   end()
        
        So:
        
        iter != Numbers.end()
        
        means:
        Keep looping while the iterator has not reached the position
        after the last element
        
        
        *iter
        Dereferences the iterator and gives us the current element
        
        iter++
        Moves the iterator to the next element
        
        
        An Iterator behaves similarly to a Pointer:
        
         Pointer:                        Iterator:
        
            p                              iter
            │                                │
            ↓                                ↓
        ┌───────┐                        ┌───────┐
        │ Value │                        │Element│
        └───────┘                        └───────┘
        
        *p      -> access the value
        *iter   -> access the current element
        
        p++     -> move forward
        iter++  -> move to the next element

    */
}