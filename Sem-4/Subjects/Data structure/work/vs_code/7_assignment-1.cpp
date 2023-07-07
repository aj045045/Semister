
// REVIEW - (7)  Write a program to demonstrate the use of dynamic memory allocation function

#include <iostream>
#include <stdlib.h>
using namespace std;

int choice()
{
    int ch;
    cout << "\n1.Malloc memory allocation" << endl;
    cout << "2.Calloc memory allocation" << endl;
    cout << "3.EXIT" << endl;
    cin >> ch;
    return ch;
}

int main()
{
    do
    {
        int *ptr, n;
        char ch;
        switch (choice())
        {
            system("cls");
        case 1:
        {
            int i = 0;
            cout << "Enter how many number you want to enter :";
            cin >> n;
            ptr = (int *)malloc(n * sizeof(int));
            if (ptr == NULL)
            {
                cout << "Memory Allocation fail" << endl;
                exit(0);
            }
            cout << "Enter the " << n << " value" << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> ptr[i];
            }
            cout << "===========[ PRINTING THE VALUES ]============" << endl;
            for (i; i < n; i++)
            {
                cout << ptr[i] << ", ";
            }
            cout << "\nDo you want to add the value Yes[Y] :";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                int v;
                cout << "Enter the total number you want to enter :";
                cin >> v;
                int r = v + n;
                ptr = (int *)realloc(ptr, sizeof(int) * v);
                if (ptr == NULL)
                {
                    cout << "memory allocation failed" << endl;
                    exit(0);
                }
                cout << "Enter the " << v << " value" << endl;
                while (i < r)
                {
                    cin >> ptr[i];
                    i++;
                }
                cout << "===========[ PRINTING THE VALUES ]============" << endl;
                for (int i = 0; i < r; i++)
                {
                    cout << ptr[i] << ", ";
                }
            }
            break;
        }
        case 2:
        {
            int i = 0;
            cout << "Enter how many number you want to enter :";
            cin >> n;
            ptr = (int *)calloc(n, sizeof(int));
            if (ptr == NULL)
            {
                cout << "Memory Allocation Failed" << endl;
                exit(0);
            }
            cout << "Enter the " << n << " value" << endl;
            for (i; i < n; i++)
            {
                cin >> ptr[i];
            }
            cout << "===========[ PRINTING THE VALUES ]============" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << ptr[i] << ", ";
            }
            cout << "\nDo you want to add the value YES[y] :";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                int v;
                cout << "Enter the total number you want to enter :";
                cin >> v;
                int r = v + n;
                ptr = (int *)realloc(ptr, sizeof(int) * v);
                if (ptr == NULL)
                {
                    cout << "memory allocation failed" << endl;
                    exit(0);
                }
                cout << "Enter the " << v << " value" << endl;
                while (i < r)
                {
                    cin >> ptr[i];
                    i++;
                }
                cout << "===========[ PRINTING THE VALUES ]============" << endl;
                for (i = 0; i < r; i++)
                {
                    cout << ptr[i] << ", ";
                }
            }
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            cout << "INVALID  INPUT" << endl;
        }
        }
    } while (true);
}
