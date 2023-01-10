/*
* 3) Write a program to create Class Person, Employee and Department and Apply respective functionalities using inheritance.
*/
#include <iostream>
#include <string>
using namespace std;
                                                                                                    // Base class person
class person
{
    int persId;
    string persName;
    long long persContact;
public:
    person(){};
    person(int id, string na, long long co);
    void print();
    ~person();
};
                                                                                                    // Derived class employee for whose Base class is person
class employee : public person
{
    int emplId;
    string emplName;
    string emplDepartment;
public:
    employee(){};
    employee(int ei, string en, string ed, int pi, string pn, int pc);
    void print();
    ~employee();
};
                                                                                                    // Derived class department for which Base class is employee
class department : public employee
{
    int depaId;
    string depaName;
public:
    department(int di, string dn, int ei, string en, string ed, int pi, string pn, long long pc);
    void print();
    ~department();
};
                                                                                                // Base class person functions
person::person(int id, string na, long long co)
{
    persId = id;
    persName = na;
    persContact = co;
}
void person::print()
{
    cout << "==============================" << endl;
    cout << "\tPERSON" << endl;
    cout << "==============================" << endl;
    cout << "Id :" << persId << "\nName :" << persName << "\nContact :" << persContact << endl;
}
person::~person()
{
    cout<<"Destructor is called: department"<<endl;
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
    cout << "==============================" << endl;
    cout << "\tEMPLOYEE" << endl;
    cout << "==============================" << endl;
    cout << "Id :" << emplId << "\nName :" << emplName << "\nDepartment :" << emplDepartment << endl;
}
employee::~employee()
    {
        cout<<"Destructor is called: employee"<<endl;
    }
                                                                                                // Derived class department functions
department::department(int di, string dn, int ei, string en, string ed, int pi, string pn, long long pc) : employee(ei, en, ed, pi, pn, pc)
{
    depaId = di;
    depaName = dn;
    cout << "\nId :" << depaId << "\nName :" << depaName << endl;
}
void department::print()
{
    employee::print();
    cout << "==============================" << endl;
    cout << "\tDEPARTMENT" << endl;
    cout << "==============================" << endl;
    cout << "Id :" << depaId << "\nName :" << depaName << endl;
}
department::~department()
{
        cout<<"Destructor is called: department"<<endl;
}
    int main()
{
    int pi, ei, di;
    long long  pc;
    string pn, en, ed, dn;
    cout << "Enter person Details" << endl;
    cout << "Id :";
    cin >> pi;
    cout << "Name :";
    cin >> pn;
    cout << "Contact :";
    cin >> pc;
    cout << " Enter employee Details" << endl;
    cout << "Id :";
    cin >> ei;
    cout << "Name :";
    cin >> en;
    cout << "Department name:";
    cin >> ed;
    cout << "Enter department Details" << endl;
    cout << "Id :";
    cin >> di;
    cout << "Name :";
    cin >> dn;
    department d1(di, dn, ei, en, ed, pi, pn, pc);
    d1.print();
}