/*
    17) Write a program to evaluate postfix expression.
*/

#include <iostream>
#include <cstring>
using namespace std;

char infix[30], postfix[30];
int top = 0;
void push(char element) {
    postfix[top] = element;
    top++;
}

char pop() {
    top--;
    return(postfix[top]);
}

char evalute(char symbol) {
    char firstElement, secondElement;
    secondElement = pop();
    firstElement = pop();
    switch (symbol) {
    case'*': {
        return firstElement * secondElement;
    }
    case'/': {
        return firstElement / secondElement;
    }
    case'+': {
        return firstElement + secondElement;
    }
    case'-': {
        return firstElement - secondElement;
    }
    case'%': {
        return firstElement % secondElement;
    }
    case'^': {
        return firstElement ^ secondElement;
    }
    }
}

int main()
{
    int length;
    cout << "Enter the infix expression :" << endl;
    cin >> infix;
    length = strlen(infix);
    for (int i = 0; i < length; i++)
    {
        if ((top == 0) || (infix[i] != '/' && infix[i] != '*' && infix[i] != '+' && infix[i] != '-' && infix[i] != '%' && infix[i] != '^'))
            push(infix[i]);
        else
            push(evalute(infix[i]));
    }
    cout << "\nAfter the evaluation of postfix expression :" << postfix;
}