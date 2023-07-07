/*
    30) Write a program to sort array elements using selection sort technique.
*/

#include <iostream>
using namespace std;
#define MAX 10

int smallestValue(int array[], int key, int numOfElement)
{
    int pos = key, small = array[key];
    for (int i = key + 1; i < numOfElement; i++)
    {
        if (array[i] < small)
        {
            small = array[i];
            pos = i;
        }
    }
    return pos;
}

void selectionSort(int array[], int numOfElement)
{
    int pos, temp;
    for (int i = 0; i < numOfElement; i++)
    {
        pos = smallestValue(array, i, numOfElement);
        temp = array[i];
        array[i] = array[pos];
        array[pos] = temp;
    }
}

void main()
{   
    int numOfElement, array[MAX];
    cout << "Enter the num of Element :";
    cin >> numOfElement;
    for (int i = 0; i < numOfElement; i++)
    {
        cout << "Enter the " << i + 1 << " value :";
        cin >> array[i];
    }
    selectionSort(array, numOfElement);
    for (int i = 0; i < numOfElement; i++)
    {
        cout << "The " << i + 1 << " value is :" << array[i] << endl;
    }
}