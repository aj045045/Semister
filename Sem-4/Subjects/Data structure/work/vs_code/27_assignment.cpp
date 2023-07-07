/*
    27) Write a program to search specific value is in array or not using Binary searchTechnique.
*/

#include <iostream>
using namespace std;
#define MAX 10

int binarySearch(int array[], int searchValue, int numOfElement)
{

    int left = 0, right = numOfElement, middle = 0;
    while (left <= right)
    {
        middle = left + (right - 1) / 2;

        if (array[middle] == searchValue)
            return middle;

        if (array[middle] < searchValue)
            left = middle + 1;

        if (array[middle] > searchValue)
            right = middle - 1;
    }
    return -1;
}

int main()
{
    int array[MAX], searchValue, numOfElement, resultPosition, temp;
    cout << "Enter the num of element :";
    cin >> numOfElement;
    for (int i = 0; i < numOfElement; i++)
    {
        cout << "Enter the " << i + 1 << " value :";
        cin >> array[i];
    }
    cout << "Enter the Search Values :";
    cin >> searchValue;
    for (int i = 0; i < numOfElement; i++)
    {
        for (int j = i + 1; j < numOfElement; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    resultPosition = binarySearch(array, searchValue, numOfElement - 1);
    cout << "The position of " << resultPosition << " is " << array[resultPosition];
    return 0;
}