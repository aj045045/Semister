/*
   22) Write a program to implement circular queue.
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 5

int circularQueue[MAX], front = -1, rear = -1;

int choice()
{
	int ch;
	cout << "\n1. ENTER" << endl;
	cout << "2. DELETE" << endl;
	cout << "3. DISPLAY" << endl;
	cout << "4.EXIT" << endl;
	cout << "\nEnter the choice :" << endl;
	cin >> ch;
	//	system("cls");
	return ch;
}
void insertInCircularQueue(int value)
{
	if (front == 0 && rear == MAX - 1)
		cout << "OVERFLOW" << endl;
	else
	{
		if (front == -1 && rear == -1)
			front = rear = 0;
		else if (rear == MAX - 1 && front != 0)
			rear = 0;
		else
			++rear;

		circularQueue[rear] = value;
		cout << "Inserted values is :" << circularQueue[rear];
	}
}

void deleteInCircularQueue()
{
	if (front == -1)
		cout << "UNDERFLOW" << endl;
	else
	{
		if (front == rear)
			front = rear = -1;
		else
		{
			if (front == MAX - 1)
				front = 0;
			else
				front++;
		}
	}
}

int main()
{
	do
	{
		switch (choice())
		{
		case 1:
		{
			int v_value;
			cout << "Enter the number :";
			cin >> v_value;
			insertInCircularQueue(v_value);
			break;
		}
		case 2:
		{
			deleteInCircularQueue();
			break;
		}
		case 3:
		{
			cout << "Displaying the circular queue" << endl;
			for (int i = front; i <= rear; i++)
			{
				cout << circularQueue[i] << endl;
			}
			break;
		}
		case 4:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "ERROR :Please choose a valid option" << endl;
			break;
		}
		}
	} while (true);
}
