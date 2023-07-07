/*
	26) Write a program to search specific value is in array or not using Linear search Technique.
*/

#include <iostream>
using namespace std;
#define MAX 10

int linearSearch(int array[], int searchValue, int numOfValues) {
	for (int i = 0; i < numOfValues; i++) {
		if (array[i] == searchValue) {
			return i;
		}
	}
	return -1;
}

int main()
{
	int numOfValues, searchValue = 0 , array[MAX], resultPosition;
	cout << "No of values to enter :" << endl;
	cin >> numOfValues;
	for (int i = 0; i < numOfValues; i++) {
		cout << "Enter the " << i + 1 << " values :";
		cin >> array[i];
	}
	cout << "Enter the search Value :";
	cin >> searchValue;
	resultPosition = linearSearch(array, searchValue, numOfValues);
	cout << "The position of value " << array[resultPosition] << " is " << resultPosition << endl;
}
