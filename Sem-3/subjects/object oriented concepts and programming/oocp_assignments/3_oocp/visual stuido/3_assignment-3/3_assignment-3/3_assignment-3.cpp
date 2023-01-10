
/*
3) Write a program to create Class Person, Employee and Department and Apply respective functionalities using inheritance.
*/
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

// Base class person
class person
{
    int persId;
    string persName;
    int persContact;

public:
    person() {};
    person(int id, string na, int co);
    void print();
};

// Derived class employee for this Base class is person
class employee : public person
{
    int emplId;
    string emplName;
    string emplDepartment;

public:
    employee() {};
    employee(int ei, string en, string ed, int pi, string pn, int pc);
    void print();
};

// Derived class department for which Base class is employee
class department : public employee
{
    int depaId;
    string depaName;

public:
    department(int di, string dn, int ei, string en, string ed, int pi, string pn, int pc);
    void print();
};

// MAIN
int main()
{
    int pi, pc, ei, di;
    string pn, en, ed, dn;
    cout << "\nEnter person Details" << endl;
    cout << "Id :";
    cin >> pi;
    cout << "Name :";
    cin >> pn;
    cout << "Contact :";
    cin >> pc;

   
    cout << "\nEnter employee Details" << endl;
    cout << "Id :";
    cin >> ei;
    cout << "Name :";
    cin >> en;
    cout << "Department :";
    cin >> ed;

    cout << "\nEnter department Details" << endl;
    cout << "Id :";
    cin >> di;
    cout << "Name :";
    cin >> dn;
    department d1(di, dn, ei, en, ed, pi, pn, pc);
    d1.print();
}

// Base class person functions
person::person(int id, string na, int co)
{
    persId = id;
    persName = na;
    persContact = co;
}

void person::print()
{
    cout << "\n==============================" << endl;
    cout << "\tPERSON" << endl;
    cout << "==============================" << endl;
    cout << "Id :" << persId << "\nName :" << persName << "\nContact :" << persContact << endl;
}

// Derived class employee functions
employee::employee(int ei, string en, string ed, int pi, string pn, int pc) : person(pi, pn, pc)
{
    emplId = ei;
    emplName = en;
    emplDepartment = ed;
}

void employee::print()
{
    person::print();
    cout << "\n\n==============================" << endl;
    cout << "\tEMPLOYEE" << endl;
    cout << "==============================" << endl;
    cout << "Id :" << emplId << "\nName :" << emplName << "\nDepartment :" << emplDepartment << endl;
}

// Derived class department functions
department::department(int di, string dn, int ei, string en, string ed, int pi, string pn, int pc) : employee(ei, en, ed, pi, pn, pc)
{
     depaId = di;
     depaName = dn;
}

void department::print()
{
    employee::print();
    cout << "\n\n==============================" << endl;
    cout << "\tDEPARTMENT" << endl;
    cout << "==============================" << endl;
    cout << "Id :" << depaId << "\nName :" << depaName << endl;
}