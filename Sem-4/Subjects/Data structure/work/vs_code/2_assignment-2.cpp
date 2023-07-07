/*
2)  Write a program to take input in array of 10 elements. Use array of pointer to
    display the array elements.
*/

#include <iostream>
using namespace std;
int main()
{
    int array[10], *ptr;
    cout << "Enter the 10 number" << endl;
    for (int i = 0; i < 10; i++)
        cin >> array[i];
    ptr = &array[0];
    cout << "\n\n===================[ Printing ]==================" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << *ptr << endl;
        ptr++;
    }
}
