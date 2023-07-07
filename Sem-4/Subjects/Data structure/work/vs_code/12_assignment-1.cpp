/*
	12) Write a program to implement singly link list of student record with following
	operations:
		a. Input Record
		b. Insert Record at beginning
		c. Insert Record at end
		d. Insert Record after given data
		e. Insert Record before given data
		f. Delete first record
		g. Delete last record
		h. Delete a particular record
		i. Display List
		j. Exit
*/

#include <iostream>
#include<stdlib.h>
using namespace std;

struct student {
	char name[20];
	int rollNo, semester;
	struct student* NEXT;
}*TOP = NULL;

struct student *createStudent();

void insertFirstRecord() {
	if (TOP == NULL)
	{
		struct student* student = NULL;
		student = createStudent();
		TOP = student;
	}
	else
		cout << "First is created already" << endl;
}

void insertAtBeginning() {
	if (TOP != NULL)
	{
		struct student* student;
		student = createStudent();
		student->NEXT = TOP;
		TOP = student;
	}
	else
		cout << "Please create the First Record" << endl;
}

void insertAtEnd() {
	if (TOP != NULL)
	{
		struct student* temp = NULL, * ptr = NULL;
		ptr = TOP;
		while (ptr->NEXT != NULL)
			ptr = ptr->NEXT;
		temp = createStudent();
		ptr->NEXT = temp;
	}
	else
		cout << "Please create the First Record" << endl;
}

void insertBeforeRecord(int rollNo) {
	if (TOP != NULL)
	{
		struct student* temp = NULL, * ptr = NULL, * prePtr = NULL;
		ptr = TOP;
		while (ptr->rollNo != rollNo)
		{
			prePtr = ptr;
			ptr = ptr->NEXT;
		}
		temp = createStudent();
		prePtr->NEXT = temp;
		temp->NEXT = ptr;
	}
	else
		cout << "Please create the First Record" << endl;
}

void insertAfterRecord(int rollNo) {
	if (TOP != NULL)
	{
		struct student* temp = NULL, * ptr = NULL;
		ptr = TOP;
		while (ptr->rollNo != rollNo)
			ptr = ptr->NEXT;
		temp = createStudent();
		temp->NEXT = ptr->NEXT;
		ptr->NEXT = temp;
	}
	else
		cout << "Please create the First Record" << endl;
}

void deleteFirstRecord() {
	if (TOP != NULL)
	{
		struct student* ptr = NULL;
		ptr = TOP;
		TOP = TOP->NEXT;
		free(ptr);
	}
	else
		cout << "Please create the First Record" << endl;
}

void deleteLastRecord() {
	if (TOP != NULL)
	{
		struct student* ptr = NULL, * prePtr = NULL;
		ptr = TOP;
		while (ptr->NEXT != NULL)
		{
			prePtr = ptr;
			ptr = ptr->NEXT;
		}
		prePtr->NEXT = NULL;
		free(ptr);
	}
	else
		cout << "Please create the First Record" << endl;
}

void deleteRecord(int rollNo) {
	if (TOP != NULL)
	{
		struct student* ptr = NULL, * prePtr = NULL;
		ptr = TOP;
		while (ptr->rollNo != rollNo)
		{
			prePtr = ptr;
			ptr = ptr->NEXT;
		}
		prePtr->NEXT = ptr->NEXT;
		free(ptr);
	}
	else
		cout << "Please create the First Record" << endl;
}

void displayRecord() {
	if (TOP != NULL)
	{
		struct student* ptr = NULL;
		ptr = TOP;
		while (ptr!= NULL)
		{
			cout << "==================[  STUDENT INFORMATION ]==================" << endl;
			cout << "Name :" << ptr->name << endl;
			cout << "Roll No :" << ptr->rollNo << endl;
			cout << "Semester :" << ptr->semester << endl;
			cout << endl;
			ptr = ptr->NEXT;
		}
	}
	else
		cout << "Please create the First Record" << endl;
}

struct student *createStudent()
{
	struct student *temp = NULL;
	temp = (struct student *)malloc(sizeof(struct student));
	cout << "==================[ Enter the student Information ]==================" << endl;
	cout << "Name :";
	cin >> temp->name;
	cout << "Roll No :";
	cin >> temp->rollNo;
	cout << "Semester :";
	cin >> temp->semester;
	temp->NEXT = NULL;
	return temp;
}

int choice()
{
	int option = 0; char character = 0;
	cout << "\n=========[ CHOOSE OPTION ]=========" << endl;
	cout << "1.Insert Record " << endl;
	cout << "2.Delete Record" << endl;
	cout << "3.Display Record" << endl;
	cout << "4.Exit" << endl;
	cin >> option;
	switch (option)
	{
	case 1: {
		cout << "A.Insert first Record " << endl;
		cout << "B.Inset Record at beginning" << endl;
		cout << "C.Inset Record at end" << endl;
		cout << "D.Inset Record after given data" << endl;
		cout << "E.Inset Record before given data" << endl;
		cin >> character;
		break;
	}
	case 2: {
		cout << "F.Delete first record" << endl;
		cout << "G.Delete last record" << endl;
		cout << "H.Delete a particular record" << endl;
		cin >> character;
		break;
	}
	}
	if (option > 2)
		return option;
	else
		return character;
}

int main() {

	do {
		switch (choice()) {
		case 'A':
		case 'a': {
			// Insert first record
			insertFirstRecord();
			break;
		}
		case 'B':
		case 'b': {
			// Insert at beginning
			insertAtBeginning();
			break;
		}
		case 'C':
		case 'c': {
			// Insert at End
			insertAtEnd();
			break;
		}
		case 'D':
		case 'd': {
			// Insert at After the particular data
			int rollNo = 0;
			cout << "Enter the roll number :";
			cin >> rollNo;
			insertAfterRecord(rollNo);
			break;
		}
		case 'E':
		case 'e': {
			// Insert at Before the particular data
			int rollNo = 0;
			cout << "Enter the roll number :";
			cin >> rollNo;
			insertBeforeRecord(rollNo);
			break;
		}
		case 'F':
		case 'f': {
			// Delete first record
			deleteFirstRecord();
			break;
		}
		case 'G':
		case 'g': {
			// Delete last record
			deleteLastRecord();
			break;
		}
		case 'H':
		case 'h': {
			// Delete particular record
			int rollNo = 0;
			cout << "Enter the roll number :";
			cin >> rollNo;
			deleteRecord(rollNo);
			break;
		}
		case 3: {
			// Display data
			displayRecord();
			break;
		}
		case 4: {
			exit(0);
			break;
		}
		default: {
			cout << "INVALID OPTION" << endl;
		}
		}
	} while (true);
	return 0;
}