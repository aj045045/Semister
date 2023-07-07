/*
    10) Write a program to create compact matrix from spares matrix using link list and make a transpose of matrix.
*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int sparseMatrix[4][5] =
    {
        {0, 0, 0, 4, 0},
        {6, 5, 0, 0, 0},
        {0, 0, 6, 0, 0},
        {0, 0, 4, 4, 0}
    };

struct node
{
    int row, col, value;
    struct node *next;
} *TOP = NULL;

void compactMatrix()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                struct node *temp;
                temp = (struct node *)malloc(sizeof(struct node));
                if (TOP == NULL)
                {
                    temp->row = i;
                    temp->col = j;
                    temp->value = sparseMatrix[i][j];
                    temp->next = NULL;
                    TOP = temp;
                }
                else
                {
                    temp->row = i;
                    temp->col = j;
                    temp->value = sparseMatrix[i][j];
                    temp->next = TOP;
                    TOP = temp;
                }
            }
        }
    }
}

void transpose()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                struct node *temp;
                temp = (struct node *)malloc(sizeof(struct node));
                if (TOP == NULL)
                {
                    temp->row = i;
                    temp->col = j;
                    temp->value = sparseMatrix[i][j];
                    temp->next = NULL;
                    TOP = temp;
                }
                else
                {
                    temp->row = j;
                    temp->col = i;
                    temp->value = sparseMatrix[i][j];
                    temp->next = TOP;
                    TOP = temp;
                }
            }
        }
    }
}

void display()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = TOP;
    cout << "----------------[ PRINTING The VALUES ]---------------" << endl;
    cout << "ROWS" << setw(10) << "COLS" << setw(10) << "VALUE" << endl;
    while (temp->next != NULL)
    {
        cout << temp->row << setw(10);
        cout << temp->col << setw(10);
        cout << temp->value << endl;
        temp = temp->next;
    }
    cout << "TEMP" << endl;
    struct node *temp1;
    temp1 = (struct node *)malloc(sizeof(struct node));
    temp1 = TOP;
    while (temp1 != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (temp1->row == i && temp1->col == j)
                {
                    cout << temp1->value << endl;
                    temp1 = temp1->next;
                }
            }
        }
    }
}

int choice()
{
    int ch;
    cout << "1. Display values" << endl;
    cout << "2. Transpose the matrix" << endl;
    cout << "3. EXIT" << endl;
    cin >> ch;
    return ch;
}

int main()
{
    do
    {
        switch (choice())
        {
        case 1:
        {
            compactMatrix();
            display();
            break;
        }
        case 2:
        {
            transpose();
            display();
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "INVALID OPTION !" << endl;
            break;
        }
        }
    } while (true);
}
