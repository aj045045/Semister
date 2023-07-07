#include <iostream>
#include <cstring>
using namespace std;

char postfix[30];
int top = 0;

void push(char element)
{
    cout << element;
    postfix[top] = element;
    top++;
}

char pop()
{
    top--;
    return postfix[top];
}

int evaluate(char symbol, int op1, int op2)
{
    switch (symbol)
    {
    case '*':
    {
        return op1 * op2;
    }
    case '/':
    {
        return op1 / op2;
    }
    case '+':
    {
        return op1 + op2;
    }
    case '-':
    {
        return op1 - op2;
    }
    case '%':
    {
        return op1 % op2;
    }
    case '^':
    {
        int result = 1;
        for (int i = 0; i < op2; i++)
        {
            result *= op1;
        }
        return result;
    }
    }
    return 0;
}

int main()
{
    char infix[30];
    int length;
    cout << "Enter the infix expression: " << endl;
    cin >> infix;
    length = strlen(infix);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(infix[i]))
        {
            push(infix[i] - '0');
        }
        else if (infix[i] != ' ')
        {
            int op2 = pop();
            int op1 = pop();
            int result = evaluate(infix[i], op1, op2);
            push(result);
        }
    }
    cout << "After the evaluation of the postfix expression: " << (int)postfix[0] << endl;
    return 0;
}
