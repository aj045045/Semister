/*
    24) Write a program to implement input restricted dequeue.
*/
#include <iostream>
using namespace std;
#define MAX 10

int inputRestrictedDeque[MAX], rightIndex = -1, leftIndex = -1;

void insertInDeque(int value)
{
    if (rightIndex == MAX - 1)
        cout << "OVERFLOW" << endl;
    else
    {
        if (leftIndex == -1)
            rightIndex = leftIndex = 0;
        else
            ++leftIndex;
        inputRestrictedDeque[leftIndex] == value;
    }
}

void deleteRightInDeque() {
    if (leftIndex == -1 || rightIndex == -1)
        cout << "UNDERFLOW" << endl;
    else {
        if (leftIndex == rightIndex)
        {
            rightIndex = -1;
            leftIndex = -1;
        }
        else
            --rightIndex;
    }
}

void deleteLeftInDeque() {
    if (leftIndex == -1 || rightIndex == -1)
        cout << "UNDERFLOW" << endl;
    else {
        if (leftIndex == rightIndex)
        {
            rightIndex = -1;
            leftIndex = -1;
        }
        else
            ++leftIndex;
    }
}

int choice()
{
    int ch;
    cout << "1. ENTER" << endl;
    cout << "2. DELETE FROM LEFT" << endl;
    cout << "3. DELETE FROM RIGHT" << endl;
    cout << "4. DISPLAY" << endl;
    cout << "5. EXIT" << endl;
    cout << "\nEnter your choice" << endl;
    cin >> ch;
    return ch;

}
int main()
{
    do {
        switch (choice())
        {
        case 1: {

            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            break;
        }
        default: {
            cout << "ERROR : Option Invalid" << endl;
            break;
        }
        }
    } while (true);
}