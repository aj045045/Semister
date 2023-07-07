
/*
	13) Write a program to implement doubly link list of student record with following
		operations:
		a. Input Record
		b. Inset Record at beginning
		c. Inset Record at end
		d. Inset Record after given data
		e. Inset Record at before given data
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
	char name[15];
	int rollNo;
	char course[10];
	int sem;
	struct record *NEXT, *PREV;
} *start = NULL;

void createRecords(struct record *rec)
{
	if (start == NULL)
		start = rec;
	else
		cout << "First Record is already exists" << endl;
}
void createRecordBeginning(struct record *temp)
{
	if (start != NULL)
	{
		temp->NEXT = start;
		start->PREV = temp;
		start = temp;
	}
	else
		cout << "First Record is not exists" << endl;
}
void createRecordEnd(struct record *temp)
{
	struct record *rec;
	rec = start;
	while (rec->NEXT != NULL)
		rec = rec->NEXT;
	rec->NEXT = temp;
	temp->PREV = rec;
}

void createRecordAfter(struct record *temp, int rollNO)
{
	struct record *rec;
	rec = start;
	while (rec->rollNo != rollNO)
		rec = rec->NEXT;
	temp->NEXT = rec->NEXT;
	temp->PREV = rec;
	rec->NEXT->PREV = temp;
	rec->NEXT = temp;
}
void createRecordBefore(struct record *temp, int rollNO)
{
	struct record *rec;
	rec = start;
	while (rec->rollNo != rollNO)
		rec = rec->NEXT;
	temp->PREV = rec->PREV;
	rec->PREV->NEXT = temp;
	temp->NEXT = rec;
	rec->PREV = temp;
}
void createRecordParticular(struct record *temp)
{
}
void deleteRecordBeginning()
{
	struct record *temp;
	temp = start;
	start = start->NEXT;
	start->PREV = NULL;
	temp->NEXT = NULL;
	free(temp);
}
void deleteRecordEnd()
{
	struct record *temp;
	temp = start;
	while (temp->NEXT != NULL)
		temp = temp->NEXT;
	temp->PREV->NEXT = NULL;
	temp->PREV = NULL;
	free(temp);
}
void deleteRecordParticular()
{
}
void display()
{
	struct record *temp;
	temp = (struct record *)malloc(sizeof(struct record));
	temp = start;
	cout << "--------[ RECORD ]---------" << endl;
	while (temp != NULL)
	{
		cout << "Name :" << temp->name << endl;
		cout << "Roll.No :" << temp->rollNo << endl;
		cout << "Course :" << temp->course << endl;
		cout << "Semester :" << temp->sem << endl;
		cout << "\n\n";
		temp = temp->NEXT;
	}
}
int choice()
{
	int opt;
	char ch = 'A';
	cout << "1.INPUT" << endl;
	cout << "2.DELETE" << endl;
	cout << "3.DISPLAY" << endl;
	cout << "4.EXIT" << endl;
	cin >> opt;
	switch (opt)
	{
	case 1:
	{
		cout << "a.Insert record ( Create record )" << endl;
		cout << "b.Insert record at beginning" << endl;
		cout << "c.Insert record at end" << endl;
		cout << "d.Insert record after given data" << endl;
		cout << "e.Insert record before given data" << endl;
		cin >> ch;
		break;
	}
	case 2:
	{
		cout << "f.Delete first record" << endl;
		cout << "g.Delete last record" << endl;
		cout << "h.Delete a particular record" << endl;
		cin >> ch;
		break;
	}
	}
	system("cls");
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
		case 3:
		{
			// TO DISPLAY
			display();
			break;
		}
		case 4:
		{
			// EXIT
			exit(0);
			break;
		}
		case 'A':
		case 'a':
		{
			// CREATE RECORDS
			struct record *temp = NULL;
			temp = (struct record *)malloc(sizeof(struct record));
			cout << "---------[ Enter student Detail ]---------" << endl;
			cout << "Name :";
			cin >> temp->name;
			cout << "Roll.No :";
			cin >> temp->rollNo;
			cout << "Course :";
			cin >> temp->course;
			cout << "Semester :";
			cin >> temp->sem;
			temp->PREV = NULL;
			temp->NEXT = NULL;
			createRecords(temp);
			break;
		}
		case 'B':
		case 'b':
		{
			// INSERT RECORD AT BEGINNING
			struct record *temp = NULL;
			temp = (struct record *)malloc(sizeof(struct record));
			cout << "---------[ Enter student Detail ]---------" << endl;
			cout << "Name :";
			cin >> temp->name;
			cout << "Roll.No :";
			cin >> temp->rollNo;
			cout << "Course :";
			cin >> temp->course;
			cout << "Semester :";
			cin >> temp->sem;
			temp->PREV = NULL;
			temp->NEXT = NULL;
			createRecordBeginning(temp);
			break;
		}
		case 'C':
		case 'c':
		{
			// INSERT RECORD AT END
			struct record *temp = NULL;
			temp = (struct record *)malloc(sizeof(struct record));
			cout << "---------[ Enter student Detail ]---------" << endl;
			cout << "Name :";
			cin >> temp->name;
			cout << "Roll.No :";
			cin >> temp->rollNo;
			cout << "Course :";
			cin >> temp->course;
			cout << "Semester :";
			cin >> temp->sem;
			temp->PREV = NULL;
			temp->NEXT = NULL;
			createRecordEnd(temp);
			break;
		}
		case 'D':
		case 'd':
		{
			// INSERT RECORD AFTER THE RECORD
			int v_name;
			cout << "Enter the rollNo you want to enter after that record :";
			cin >> v_name;
			struct record *temp = NULL;
			temp = (struct record *)malloc(sizeof(struct record));
			cout << "---------[ Enter student Detail ]---------" << endl;
			cout << "Name :";
			cin >> temp->name;
			cout << "Roll.No :";
			cin >> temp->rollNo;
			cout << "Course :";
			cin >> temp->course;
			cout << "Semester :";
			cin >> temp->sem;
			temp->PREV = NULL;
			temp->NEXT = NULL;
			createRecordAfter(temp, v_name);
			break;
		}
		case 'E':
		case 'e':
		{
			// INSERT RECORD BEFORE RECORD
			int v_name;
			cout << "Enter the rollNo you want to enter after that record :";
			cin >> v_name;
			struct record *temp = NULL;
			temp = (struct record *)malloc(sizeof(struct record));
			cout << "---------[ Enter student Detail ]---------" << endl;
			cout << "Name :";
			cin >> temp->name;
			cout << "Roll.No :";
			cin >> temp->rollNo;
			cout << "Course :";
			cin >> temp->course;
			cout << "Semester :";
			cin >> temp->sem;
			createRecordAfter(temp, v_name);
			break;
		}
		case 'F':
		case 'f':
		{
			// DELETE RECORD AT BEGINNING
			deleteRecordBeginning();
			break;
		}
		case 'G':
		case 'g':
		{
			// DELETE RECORD AT END
			deleteRecordEnd();
			break;
		}
		case 'H':
		case 'h':
		{
			// DELETE RECORD AT PARTICULAR PLACE
			deleteRecordParticular();
			break;
		}
		default:
		{
			cout << "INVALID OPTIONS !" << endl;
			break;
		}
		}
	} while (true);
}
