
//REVIEW - (6)  Write a menu driven program to implement stack with it�s operation with all the validations.

#include <iostream>
using namespace std;
int stack[30];
int top = 0;

void push(int val)
{
    if (top == 29)
    {
        cout << "Stack is overflow" << endl;
    }
    else
    {
        stack[top] = val;
        top++;
    }
}

void pop()
{
    if (top == 0)
    {
        cout << "Stack is underflow" << endl;
    }
    else
    {
        top--;
    }
}

void peep(int val)
{
    for (int i = 0; i < top; i++)
    {
        if (stack[i] == val)
            cout << "Values is found" << endl;
    }
}

void change(int index, int val)
{
    stack[index] = val;
}

void display()
{
    cout << "===========[ PRINTING THE VALUES ]============" << endl;
    for (int i = 0; i < top; i++)
        cout << stack[i] << endl;
}

void isFull()
{
    if (top == 29)
        cout << "Stack is overflow" << endl;
    else
        cout << "Stack is not overflow" << endl;
}

void isEmpty()
{
    if (top == 0)
        cout << "Stack is underflow" << endl;
    else
        cout << "Stack is not underflow" << endl;
}

int choice()
{
    int ch;
    cout << "1. Insert value (PUSH)" << endl;
    cout << "2. Delete value (POP)" << endl;
    cout << "3. Find value (PEEP)" << endl;
    cout << "4. Replace value (CHANGE)" << endl;
    cout << "5. Check stack is overflow(IS FULL)" << endl;
    cout << "6. Check stack is underflow (IS EMPTY)" << endl;
    cout << "7. Display the value of stack" << endl;
    cout << "8. Exit" << endl;
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
        { // PUSH
            int val;
            cout << "Enter the value you want to add in list :";
            cin >> val;
            push(val);
            break;
        }
        case 2:
        { // POP
            pop();
            break;
        }
        case 3:
        { // PEEP
            int val;
            cout << "Enter the value";
            cin >> val;
            peep(val);
            break;
        }
        case 4:
        { // CHANGE
            int index, val;
            cout << "Enter the place you want to change :";
            cin >> index;
            cout << "Enter the value";
            cin >> val;
            change(index, val);
            display();
            break;
        }
        case 5:
        { // isFull
            isFull();
            break;
        }
        case 6:
        { // isEmpty
            isEmpty();
            break;
        }
        case 7:
        { // DISPLAY
            display();
            break;
        }
        case 8:
        { // EXIT
            exit(0);
            break;
        }
        default:
        {
            cout << "INVALID OPTION!" << endl;
            break;
        }
        }
    } while (true);
    return 0;
}