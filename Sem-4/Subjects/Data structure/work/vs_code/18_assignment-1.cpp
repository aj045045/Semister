/*
    18) Write a program to convert infix expression to prefix expression.
*/

#include <iostream>
#include <cstring>
using namespace std;

char infix[30], postfix[30], stack[15];
int top = 0;
void push(char element)
{
    stack[top] = element;
    top++;
}

char pop() 
{
    top--;
    return stack[top];
}

int precedence(char symbol)
{
	switch (symbol)
	{
	case')':
	case'(': {
		return 0;
	}
	case'+':
	case'-': {
		return 1;
	}
	case'*':
	case'/': {
		return 2;
	}
	case'^': {
		return 3;
	}
	}
	return 0;
}

int main()
{
	int length, j = 0;
	char temp;
	cout << "Enter the infix expression to convert it into prefix expression";
	cin >> infix;
	_strrev(infix);
	
	length = strlen(infix);
	for (int i = 0; i < length; i++)
	{
		if (infix[i] != '(' && infix[i] != ')' && infix[i] != '*' && infix[i] != '/' && infix[i] != '-' && infix[i] != '+' && infix[i] != '%' && infix[i] != '^') {
			postfix[j++] = infix[i];
		}
		else
		{
			if (top == 0)
				push(stack[i]);
			else
			{
				if (infix[i] == '*' || infix[i] == '/' || infix[i] == '-' || infix[i] == '+' || infix[i] == '%' || infix[i] == '^')
				{
					if (precedence(infix[i]) <= precedence(stack[top - 1]))
					{
						temp = pop();
						postfix[j++] = temp;
						push(infix[i]);
					}
					else
					{
						push(infix[i]);
					}
				}
				else
				{
					if (infix[i] == '(')
						push(infix[i]);
					else
					{
						do {
							temp = pop();
							postfix[j++] = temp;
						} while (temp != '(');
					}
				}
			}
		}
	}
	while (top != 0)
		postfix[j++] = pop();
	_strrev(postfix);
	cout << "After convert the infix to prefix expression :" << postfix;
}