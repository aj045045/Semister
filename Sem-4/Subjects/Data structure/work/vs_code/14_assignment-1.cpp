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

struct record {
    char name[10], course[10];
    int sem, rollNo;
    struct record* prev, * next;
};
struct record* inputRecord();
struct record* first = NULL;

void createRecord() {
    if (first == NULL)
    {
        first = inputRecord();
        first->next = first;
    }
    else
        cout << "ERROR :First record is already created" << endl;
}

void createRecordBeginning() {
    if (first != NULL)
    {
        struct record* ptr, * temp;
        temp = inputRecord();
        ptr = first;
        while (ptr->next != first)
            ptr = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    else
        cout << "ERROR :First record is not created" << endl;
}
void createRecordEnd() {
    if (first != NULL)
    {
    struct record* ptr, * temp;
    temp = inputRecord();
    ptr = first;
        while (ptr->next != first)
            ptr = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
        temp->next = first;
        first->prev = temp;
    }
    else
        cout << "ERROR :First record is not created" << endl;
}
void createRecordAfter(char name[20])
{
    struct record* ptr, * temp;
    temp = inputRecord();
    ptr = first;
    while (ptr->name != name)
        ptr = ptr->next;
    temp->next = ptr->next;
    ptr->next->prev = temp;
    temp->prev = ptr;
    ptr->next = temp; 
}

void createRecordBefore(char name[20])
{
    struct record* ptr, * temp;
    temp = inputRecord();
    ptr = first;
    while (ptr->name != name)
        ptr = ptr->next;
    temp->prev = ptr->prev;
    ptr->prev->next = temp;
    temp->next = ptr;
    ptr->prev = temp;
}

void deleteRecordBeginning()
{
    struct record* ptr;
    first->prev->next = first->next;
    first->next->prev = first->prev;
    first = first->next;
    ptr = first;
    free(ptr);
}

void deleteRecordEnd()
{
    struct record* ptr, * temp;
    ptr = first;
    while (ptr->next != first)
        ptr = ptr->next;
    ptr->prev->next = first;
    first->prev = ptr->prev;
    free(ptr);
}
void deleteParticular(char name[20])
{
    struct record* ptr, * temp;
    ptr = first;
    while (ptr->name != name)
        ptr = ptr->next;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
}
struct record * inputRecord()
{
    struct record* temp;
    temp = (struct record*)malloc(sizeof(struct record));
    cout << "-------------------------[ Enter Record ]-------------------------" << endl;
    cout << "Name :"; cin >> temp->name;
    cout << "Roll.No :"; cin >> temp->rollNo;
    cout << "Course :"; cin >> temp->course;
    cout << "Semester :"; cin >> temp->sem;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void display()
{
    struct record* temp;
    temp = first;
    cout << "-------------[ DISPLAY RECORDS ]-------------------" << endl;
    do
    {
        cout << "Name :" << temp->name << endl;
        cout << "Roll.No :" << temp->rollNo << endl;
        cout << "Course :" << temp->course << endl;
        cout << "Semester :" << temp->sem << endl;
        cout << "\n" << endl;
        temp = temp->next;
    } while (temp != first);
}

int choice()
{
    int opt;
    char ch = 'A';
    if(first!=NULL)
        cout << "\n\n" << endl;
    cout << "1.INPUT" << endl;
    cout << "2.DELETE" << endl;
    cout << "3.DISPLAY" << endl;
    cout << "4.EXIT" << endl;
    cin >> opt;
    switch (opt) {
    case 1: {
        cout << "a.Insert record ( Create record )" << endl;
        cout << "b.Insert record at beginning" << endl;
        cout << "c.Insert record at end" << endl;
        cout << "d.Insert record after given data" << endl;
        cout << "e.Insert record before given data" << endl;
        cin >> ch;
        break;
    }
    case 2: {
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
    do {
        switch (choice())
        {
        case 'A':
        case 'a': {
            createRecord();
            break;
        }
        case 'B':
        case 'b': {
            createRecordBeginning();
            break;
        }
        case 'C':
        case 'c': {
            createRecordEnd();
            break;
        }
        case 'D':
        case 'd': {
            char name[20];
            cout << "Enter the Name to delete the Record :";
            cin >> name;
            createRecordAfter(name);
            break;
        }
        case 'E':
        case 'e': {
            char name[20];
            cout << "Enter the Name to delete the Record :";
            cin >> name;
            createRecordBefore(name);
            break;
        }
        case 'F':
        case 'f': {
            deleteRecordBeginning();
            break;
        }
        case 'G':
        case 'g': {
            deleteRecordEnd();
            break;
        }
        case 'H':
        case 'h': {
            char name[20];
            cout << "Enter the Name to delete the Record :";
            cin >> name;
            deleteParticular(name);
            break;
        }
        case 3: {
            display();
            break;
        }
        case 4: {
            exit(0);
            break;
        }
        default: {
            cout << "ENVALID INPUT !";
        }
        }
    } while (true);
}
