
/*

    13) Write a program to implement doubly link list of student record with following operations:
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

struct student
{
    char name[15];
    int rollNo;
    char course[10];
    int sem;
    struct student *NEXT, *PREV;
} *TOP = NULL;

struct student *createRecord()
{
    struct student *temp = NULL;
    temp = (struct student *)malloc(sizeof(struct student));
    cout << "\n===============[ INSERT RECORD ]===============" << endl;
    cout << "Name :";
    cin >> temp->name;
    cout << "Roll No :";
    cin >> temp->rollNo;
    cout << "Course :";
    cin >> temp->course;
    cout << "Semester :";
    cin >> temp->sem;
    temp->NEXT = NULL;
    temp->PREV = NULL;
    return temp;
}

void createStudent()
{
    if (TOP == NULL)
    {
        TOP = createRecord();
        TOP->NEXT = TOP;
    }
    else
        cout << "First is create already" << endl;
}

void insertAtBeginning()
{
    if (TOP != NULL)
    {
        struct student *temp = NULL, *ptr = NULL;
        temp = createRecord();
        ptr = TOP;
        while (ptr->NEXT != TOP)
            ptr = ptr->NEXT;
        temp->PREV = ptr;
        ptr->NEXT = temp;
        temp->NEXT = TOP;
        TOP->PREV = temp;
        TOP = temp;
    }
    else
        cout << "Please create the first record" << endl;
}

void insertAtEnd()
{
    if (TOP != NULL)
    {
        struct student *temp = NULL, *ptr = NULL;
        temp = createRecord();
        ptr = TOP;
        while (ptr->NEXT != TOP)
            ptr = ptr->NEXT;
        ptr->NEXT = temp;
        temp->PREV = ptr;
        temp->NEXT = TOP;
        TOP->PREV = temp;
    }
    else
        cout << "Please create the first record" << endl;
}

void insertAfterRecord(int rollNo)
{
    if (TOP != NULL)
    {
        struct student *temp = NULL, *ptr = NULL;
        temp = createRecord();
        while (ptr->rollNo != rollNo)
            ptr = ptr->NEXT;
        temp->NEXT = ptr->NEXT;
        ptr->NEXT->PREV = temp;
        temp->PREV = ptr;
        ptr->NEXT = temp;
    }
    else
        cout << "Please create the first record" << endl;
}

void insertBeforeRecord(int rollNo)
{
    if (TOP != NULL)
    {
        struct student *temp = NULL, *ptr = NULL;
        temp = createRecord();
        while (ptr->rollNo != rollNo)
            ptr = ptr->NEXT;
        temp->PREV = ptr->PREV;
        ptr->PREV->NEXT = temp;
        temp->NEXT = ptr;
        ptr->PREV = temp;
    }
    else
        cout << "Please create the first record" << endl;
}

void deleteAtBeginning()
{
    if (TOP != NULL)
    {
        struct student *temp = NULL;
        temp = TOP;
        TOP->PREV->NEXT = TOP->NEXT;
        TOP->NEXT->PREV = TOP->PREV;
        TOP = TOP->NEXT;
        free(temp);
    }
    else
        cout << "Please create the first record" << endl;
}

void deleteAtEnd()
{
    if (TOP != NULL)
    {
        struct student *ptr = NULL;
        ptr = TOP;
        while (ptr->NEXT != TOP)
            ptr = ptr->NEXT;
        ptr->PREV->NEXT = TOP;
        TOP->PREV = ptr->PREV;
        free(ptr);
    }
    else
        cout << "Please create the first record" << endl;
}

void deleteRecord(int rollNo)
{
    if (TOP != NULL)
    {
        struct student *temp = NULL;
        temp = TOP;
        while (temp->rollNo != rollNo)
            temp = temp->NEXT;
        temp->PREV->NEXT = temp->NEXT;
        temp->NEXT->PREV = temp->PREV;
        free(temp);
    }
    else
        cout << "Please create the first record" << endl;
}

void displayRecord()
{
    if (TOP != NULL)
    {
        struct student *temp = NULL;
        temp = TOP;
        while (true)
        {
            cout << "\n===============[ DISPLAY RECORD ]===============" << endl;
            cout << "Name :" << temp->name << endl;
            cout << "Roll No :" << temp->rollNo << endl;
            cout << "Course :" << temp->course << endl;
            cout << "Semester :" << temp->sem << endl;
            temp = temp->NEXT;
            if (temp = TOP)
                break;
        }
    }
    else
        cout << "Please create the first record" << endl;
}

int choice()
{
    int opt;
    char ch = 'X';
    cout << "\n1.INPUT" << endl;
    cout << "2.DELETE" << endl;
    cout << "3.DISPLAY" << endl;
    cout << "4.EXIT" << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    {
        cout << "A.Insert record ( Create record )" << endl;
        cout << "B.Insert record at beginning" << endl;
        cout << "C.Insert record at end" << endl;
        cout << "D.Insert record after given data" << endl;
        cout << "E.Insert record before given data" << endl;
        cin >> ch;
        break;
    }
    case 2:
    {
        cout << "F.Delete first record" << endl;
        cout << "G.Delete last record" << endl;
        cout << "H.Delete a particular record" << endl;
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
        case 'A':
        case 'a':
        {
            // Create Record
            createStudent();
            break;
        }
        case 'B':
        case 'b':
        {
            // Insert at Beginning
            insertAtBeginning();
            break;
        }
        case 'C':
        case 'c':
        {
            // Insert at End
            insertAtEnd();
            break;
        }
        case 'D':
        case 'd':
        {
            // Insert After the particular record
            int rollNo;
            cout << "Insert Record after the given roll.No :";
            cin >> rollNo;
            insertAfterRecord(rollNo);
            break;
        }
        case 'E':
        case 'e':
        {
            // Insert Before the particular record
            int rollNo;
            cout << "Insert Record before the given roll.No :";
            cin >> rollNo;
            insertBeforeRecord(rollNo);
            break;
        }
        case 'F':
        case 'f':
        {
            // Delete First Record
            deleteAtBeginning();
            break;
        }
        case 'G':
        case 'g':
        {
            // Delete End Record
            deleteAtEnd();
            break;
        }
        case 'H':
        case 'h':
        {
            // Delete the Particular Record
            int rollNo;
            cout << "Delete Record the given roll.No :";
            cin >> rollNo;
            deleteRecord(rollNo);
            break;
        }
        case 3:
        {
            // Display Record
            displayRecord();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "INVALID INPUT " << endl;
            break;
        }
        }
    } while (true);
    return 0;
}