// 16) Write a program to convert infix expression to postfix expression.

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define size 10

char stack[size];
int tos = 0, ele;
void push(char);
char pop();
void show();
char infix[30], postfix[30];
int prec(char);

// Functions for operations on stack
void push(char ele)
{
	stack[tos] = ele;
	tos++;
}

char pop()
{
	tos--;
	return (stack[tos]);
}

void show()
{
	int x = tos;
	cout << "--The Stack elements are....." << endl;
	while (x != 0)
		cout << stack[--x] << endl;
}
// Function to get the precedence of an operator
int prec(char symbol)
{
	switch (symbol)
	{
	case ')':
	case '(':
	{
		return 0;
	}
	case '+':
	case '-':
	{
		return 1;
	}
	case '*':
	case '/':
	{
		return 2;
	}
	case '^':
	{
		return 3;
	}
	}
	return 0;
}

int main()
{
	int i = 0, j = 0, k = 0, length;
	char temp;
	cout << "\nEnter an infix expression:" << endl;
	cin >> infix;
	cout << "\nThe infix expression are :" << infix << endl;
	length = strlen(infix);
	for (i = 0; i < length; i++)
	{
		// Numbers are added to the output QUE
		if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '^' && infix[i] != ')' && infix[i] != '(')
		{
			postfix[j++] = infix[i];
			cout << "\nThe element added to Q is :" << infix[i] << endl;
		}
		// If an operator or a bracket is encountered...
		else
		{
			if (tos == 0) // If there are no elements in the stack, the operator is added to it
			{
				push(infix[i]);
				cout << "\nThe pushed element is :" << infix[i] << endl;
			}
			else
			{ // Operators or pushed or poped based on the order of precedence
				if (infix[i] != ')' && infix[i] != '(')

				{
					if (prec(stack[tos - 1]) < prec(infix[i]))
					{
						push(infix[i]);
						cout << "\nThe pushed element is:" << infix[i] << endl;
						show();
					}
					else
					{
						temp = pop();
						cout << "\n the poped element is :" << temp << endl;
						postfix[j++] = temp;
						push(infix[i]);
						cout << "\n The pushed element is  :" << infix[i] << endl;
						show();
					}
				}
				else
				{
					if (infix[i] == '(')
					{
						push(infix[i]);
						cout << "\nThe pushed-- element is :" << infix[i] << endl;
					}
					if (infix[i] == ')')
					{
						temp = pop();
						while (temp != '(')
						{
							postfix[j++] = temp;
							cout << "\nThe element added to Q is :" << temp << endl;
							cout << "\n the poped element is  :" << temp << endl;
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
}
