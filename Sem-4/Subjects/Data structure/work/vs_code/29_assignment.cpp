/*
    29) Write a program to sort array elements using insertion sort technique.
*/

#include <iostream>
using namespace std;
#define MAX 10

void insertionSort(int array[], int numOfElement)
{ 
    int temp, j = 1, i;
    for (i = 1; i < numOfElement; i++)
    {
        temp = array[i];
        j = i - 1;
        while ((temp < array[j]) && (j >= 0))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void main()
{
    int array[MAX], numOfElement;
    cout << "Enter the num of Element :";
    cin >> numOfElement;
    for (int i = 0; i < numOfElement; i++)
    {
        cout << "Enter the " << i + 1 << " value :";
        cin >> array[i];
    }
    insertionSort(array, numOfElement);
    cout << "The sorted  values are " << endl;
    for (int i = 0; i < numOfElement; i++)
        cout << array[i]<<" ";
}

