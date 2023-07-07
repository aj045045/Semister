
//REVIEW -	(8) Write a menu driven program to implement stack with it's operation with all the validations using link list.

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
} *top = NULL;

void push(int val)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if (top == NULL)
	{
		temp->data = val;
		temp->next = NULL;
		top = temp;
		cout << "Entered in push" << endl;
	}
	else
	{
		temp->data = val;
		temp->next = top;
		top = temp;
		cout << "Entered in push 2" << endl;
	}
}

void display()
{
	struct node *temp1;
	temp1 = (struct node *)malloc(sizeof(struct node));
	temp1 = top;
	cout << "DISPLAY" << endl;
	do
	{
		cout << "Value is :" << temp1->data << endl;
		temp1 = temp1->next;
	} while (temp1 != NULL);
}
void pop()
{
	struct node *temp1;
	temp1 = (struct node *)malloc(sizeof(struct node));
	temp1 = top;
	top = top->next;
	temp1->next = NULL;
	free(temp1);
}
int choice()
{

	int ch;
	cout << "1.Enter new value" << endl;
	cout << "2.Delete the value" << endl;
	cout << "3.Display the value" << endl;
	cout << "4.EXIT" << endl;
	cin >> ch;
	return ch;
}
int main()
{
	int val;
	int ch;
	do
	{
		ch = choice();
		switch (ch)
		{
		case 1:
		{
			cout << "Enter the value :";
			cin >> val;
			push(val);
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			display();
			break;
		}
		case 4:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "INVALID INPUT!" << endl;
			break;
		}
		}
	} while (ch != 0);
	return 0;
}
