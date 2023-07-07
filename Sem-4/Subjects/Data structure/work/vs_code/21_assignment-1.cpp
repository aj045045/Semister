/*
	21) Write a Program to implement queue using array.
*/

#include <iostream>
#include<cstring>
#include <stdlib.h>
using namespace std;
#define MAX 10

int queue[MAX], FRONT = -1, REAR = -1;

int choice()
{
	int ch;
	cout << "\n1. ENTER " << endl;
	cout << "2. DELETE " << endl;
	cout << "3. DISPLAY " << endl;
	cout << "4. EXIT " << endl;
	cout << "\nEnter your choice :" << endl;
	cin >> ch;
//	system("cls");
	return ch;
}

void insertQueue(int NUM)
{
	if (REAR == MAX - 1)
		cout << "OVERFLOW" << endl;
	if (FRONT == -1)
		REAR = FRONT = 0;
	else
		++REAR;
	queue[REAR] = NUM;
	cout << "Insert " << queue[REAR];
}

void deleteQueue()
{
	if (FRONT == -1 || FRONT > REAR)
		cout << "UNDERFLOW" << endl;
	else 
		++FRONT;
	cout << "DELETE " << queue[FRONT];
}
int main()
{	
	do {
		switch (choice())
		{
		case 1: {
			int num;
			cout << "Enter the number to insert :";
			cin >> num;
			insertQueue(num);
			break;
		}
		case 2: {
			deleteQueue();
			break;
		}
		case 3: {
			cout << "Displaying the QUEUE" << endl;
			for (int i = FRONT; i <= REAR; i++)
			{
				cout << queue[i] << endl;
			}
			break;
		}
		case 4: {
			exit(0);
			break;
		}
		}
	} while (true);
}