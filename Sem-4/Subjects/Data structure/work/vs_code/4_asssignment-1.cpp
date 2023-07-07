/*
    4) Define two array A and B. and merge both array in array C.
*/

#include <iostream>
using namespace std;

int main()
{
    int array_a[10], val_a, array_b[10], val_b, array_c[20];
    cout << "Enter how many element you want to enter in the first list:";
    cin >> val_a;
    cout << "Enter " << val_a << " element" << endl;
    for (int i = 0; i < val_a; i++)
    {
        cin >> array_a[i];
    }
    cout << "Enter how many element you want to enter in the second list :";
    cin >> val_b;
    cout << "Enter " << val_b << " element" << endl;
    for (int i = 0; i < val_b; i++)
        cin >> array_b[i];
    cout << "Merging both the list to the third list" << endl;
    int j = 0;
    for (int i = 0; i < val_a + val_b; i++)
    {
        if (i < val_a)
        {
            array_c[i] = array_a[i];
        }
        else
        {
            array_c[i] = array_b[j];
            j++;
        }
    }

    cout << "==========[ PRINTING THE VALUE ]=============" << endl;
    for (int i = 0; i < val_a + val_b; i++)
        cout << array_c[i] << ", ";
}
