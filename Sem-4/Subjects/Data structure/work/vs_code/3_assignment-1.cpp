
// REVIEW - (3)  Write program to define an array. Insert elements and display elements.
//              After display insert the element at particular location in array.

#include <iostream>
using namespace std;

int main()
{
    int array[10], pos, num;
    cout << "Enter 9 Number" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "Num " << i << " :";
        cin >> array[i];
    }
    cout << "Enter location where you want to enter the number :";
    cin >> pos;
    cout << "Enter number to insert into previous location :";
    cin >> num;
    int temp1 = array[pos], temp2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i >= pos)
        {
            temp2 = array[i + 1];
            array[i + 1] = temp1;
            temp1 = temp2;
        }
    }
    array[pos] = num;
    cout << "Printing the array" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }
}