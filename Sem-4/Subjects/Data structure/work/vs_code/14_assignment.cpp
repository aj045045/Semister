/*
14) Write a program to implement circular link list of student record with following operations:
a. Input Record
b. Inset Record at beginning
c. Inset Record at end
d. Inset Record before given data
e. Inset Record after given data
f. Delete first record
g. Delete last record
h. Delete a particular record
i. Display List
j. Exit
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct record
{
	int rollNo, sem;
	char course[15], name[15];
	struct record *next, *prev;
};
struct record *start = NULL;

struct record *input();

struct record *input()
{
	struct record *temp;
	temp = (struct record *)malloc(sizeof(struct record));
	cout << "Name :";
	cin >> temp->name;
	cout << "Roll.No :";
	cin >> temp->rollNo;
	cout << "Course :";
	cin >> temp->course;
	cout << "Semester :";
	cin >> temp->sem;
	return temp;
}

void insertRecord()
{
	struct record *temp = NULL;
	temp = input();
	if (start == NULL)
	{
		start = temp;
		start->next = start;
		cout << "First Record is created" << endl;
	}
	else
		cout << "First Record is already exists" << endl;
}
void insertAtBeginning()
{
	struct record *temp, *ptr = NULL;
	temp = input();
	ptr = start;
	while (ptr->next != start)
		ptr = ptr->next;
	temp->prev = ptr;
	ptr->next = temp;
	temp->next = start;
	start->prev = temp;
	start = temp;
}
void insertAtEnd()
{
	struct record *temp, *ptr = NULL;
	temp = input();
	ptr = start;
	while (ptr->next != start)
		ptr = ptr->next;
	temp->prev = ptr;
	ptr->next = temp;
	temp->next = start;
	start->prev = temp;
}
void insertBefore(int v_rollNo)
{
	struct record *temp, *ptr = NULL;
	temp = input();
	ptr = start;
	while (ptr->rollNo != v_rollNo)
		ptr = ptr->next;
	temp->prev = ptr->prev;
	temp->next = ptr;
	ptr->prev->next = temp;
	ptr->prev = temp;
}
void insertAfter(int v_rollNo)
{
	struct record *temp, *ptr = NULL;
	temp = input();
	ptr = start;
	while (ptr->rollNo != v_rollNo)
		ptr = ptr->next;
	temp->next = ptr->next;
	temp->prev = ptr;
	ptr->next->prev = temp;
	ptr->next = temp;
}
void deleteAtBeginning()
{
	struct record *temp, *ptr = NULL;
	ptr = start;
	while (ptr->next != start)
		ptr = ptr->next;
	ptr->next = start->next;
	start->next->prev = ptr;
	temp = start;
	start = start->next;
	free(temp);
}
void deleteAtEnd()
{
	struct record *ptr = NULL;
	ptr = start;
	while (ptr->next != start)
		ptr = ptr->next;
	ptr->prev->next = start;
	start->prev = ptr->prev;
	ptr->prev = NULL;
	ptr->next = NULL;
	free(ptr);
}
void deleteParticular(int v_rollNo)
{
	struct record *ptr = NULL;
	ptr = start;
	while (ptr->rollNo != v_rollNo)
		ptr = ptr->next;
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	free(ptr);
}
void display()
{
	struct record *temp = NULL;
	temp = start;
	cout << "-------------[ PRINTING RECORDS ]-------------" << endl;
	while (true)
	{
		cout << "Name :" << temp->name << endl;
		cout << "Roll.No :" << temp->rollNo << endl;
		cout << "Course :" << temp->course << endl;
		cout << "Semester :" << temp->sem << endl;
		cout << endl
			 << endl;
		temp = temp->next;
		if (temp == start)
			break;
	}
}

int choice()
{
	char ch = 'a';
	int opt;
	cout << "1. INPUT" << endl;
	cout << "2. DELETE" << endl;
	cout << "3. DISPLAY" << endl;
	cout << "4. EXITS" << endl;
	cin >> opt;
	if (opt == 1)
	{
		cout << "a. Input record (create first record)" << endl;
		cout << "b. Input record at beginning" << endl;
		cout << "c. Input record at end" << endl;
		cout << "d. Inset Record before given data " << endl;
		cout << "e.Inset Record after given data" << endl;
		cin >> ch;
	}
	if (opt == 2)
	{
		cout << "f. Delete first record" << endl;
		cout << "g. Delete last record" << endl;
		cout << "h. Delete a particular record" << endl;
		cin >> ch;
	}
	//	system("cls");
	if (opt < 3)
		return ch;
	else
		return opt;
}
int main()
{
	do
	{
		switch (choice())
		{
		case 'a':
		case 'A':
		{
			// a.Input Record
			insertRecord();
			break;
		}
		case 'b':
		case 'B':
		{
			// b.Inset Record at beginning
			insertAtBeginning();
			break;
		}
		case 'c':
		case 'C':
		{
			// c.Inset Record at end
			insertAtEnd();
			break;
		}
		case 'd':
		case 'D':
		{
			// d.Inset Record before given data
			int rollNo;
			cout << "Enter roll number that to enter the values ( BEFORE )" << endl;
			cin >> rollNo;
			insertBefore(rollNo);
			break;
		}
		case 'e':
		case 'E':
		{
			// e.Inset Record after given data
			int rollNo;
			cout << "Enter roll number that to enter the values ( AFTER )" << endl;
			cin >> rollNo;
			insertAfter(rollNo);
			break;
		}
		case 'f':
		case 'F':
		{
			// f.Delete first record
			deleteAtBeginning();
			break;
		}
		case 'g':
		case 'G':
		{
			// g.Delete last record
			deleteAtEnd();
			break;
		}
		case 'h':
		case 'H':
		{
			// h.Delete a particular record
			int rollno;
			cout << "Enter roll number that to enter the values ( DELETE )" << endl;
			cin >> rollno;
			deleteParticular(rollno);
			break;
		}
		case 3:
		{
			// i.Display List
			display();
			break;
		}
		case 4:
		{
			// j.Exit
			exit(0);
			break;
		}
		default:
		{
			cout << "INVALID INPUT !" << endl;
			break;
		}
		}
		cout << "\n\n";
	} while (true);
	return 0;
}
