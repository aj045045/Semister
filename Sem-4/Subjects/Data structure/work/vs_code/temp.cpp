#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define SIZE 10
char stack[SIZE];
int tos = 0, element;
void show();
void push(char);
char pop();
char infix[30], postfix[30];
int symbol(char);

int main(int argc, char const* argv[])
{
    int i = 0, j = 0, length;
    cout << "Enter the string for infix expressions :";
    cin >> infix;
    length = strlen(infix);
    for (i; i < length; i++)
    {
        if (infix[i] != '(' && infix[i] != ')' && infix[i] != '/' && infix[i] != '*' && infix[i] != '+' && infix[i] != '-' && infix[i] != '^')
        {
            postfix[j++] = infix[i];
            cout << "Element added to postfix :" << infix[i] << endl;
        }
        else
        {
            if (tos == 0)
            {
                push(infix[i]);
                cout << "Element is pushed :" << infix[i] << endl;
            }
            else
            {
                if (infix[i] != '(' && infix[i] != ')')
                {
                    if (symbol(stack[tos - 1]) >= symbol(infix[i]))
                    {
                        char temp;
                        temp = pop();
                        cout << "Poped elements is :" << temp << endl;
                        postfix[j++] = temp;
                        push(infix[i]);
                        cout << "Push element to the stack :" << infix[i] << endl;
                        show();
                    }
                    else
                    {
                        push(infix[i]);
                        cout << "The pushed element is :" << infix[i] << endl;
                        show();
                    }
                }
                else
                {
                    if (infix[i] == '(')
                    {
                        push(infix[i]);
                        cout << "Pushed element to stack " << infix[i] << endl;
                    }
                    if (infix[i] == ')')
                    {
                        char temp;
                        temp = pop();
                        while (temp != '(')
                        {
                            postfix[j++] = temp;
                            cout << "Element added to postfix and poped from the stack :" << temp << endl;
                            temp = pop();
                        }
                    }
                }
            }
        }
        cout << "\nthe infix expression is :" << postfix << endl;
    }
    while (tos != 0)
        postfix[j++] = pop();
    cout << "the postfix expression is :\n"
        << postfix << endl;
    return 0;
}

void show()
{
    int x = tos;
    cout << "The postfix notations are..." << endl;
    while (x != 0)
        cout << stack[--x] << endl;
}

void push(char element)
{
    stack[tos] = element;
    tos++;
}

char pop()
{
    tos--;
    return (stack[tos]);
}

int symbol(char refer)
{
    if (refer == '(' || refer == ')')
        return 0;
    if (refer == '+' || refer == '-')
        return 1;
    if (refer == '*' || refer == '/')
        return 2;
    if (refer == '^')
        return 3;
}