/*
* 9)    Use an Employee Class to write records of employee to a file. Include a menu
*       that will allow the user to select any of the following features.

*       a. Add a new record.
*       b. Modify an existing record.
*       c. Retrieve and display an entire record for a given name.
*       d. Generate a complete list of all names, addresses and telephone numbers.
*       e. End of the computation.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class employee
{
    int empId;
    string empName;
    int empSalary;

public:
    employee()
    {
        empId = 0;
        empSalary = 0;
    };
    employee(int v_empId, string v_empName, int v_empSalary);
    void display();
    void find(string name);
    void modify(employee &emp, string v_empName, int ch);
};

employee::employee(int v_empId, string v_empName, int v_empSalary)
{
    empId = v_empId;
    empName = v_empName;
    empSalary = v_empSalary;
}

void employee::display()
{
    cout << "\nEmployee id: " << empId << endl;
    cout << "Employee name: " << empName << endl;
    cout << "Employee salary: " << empSalary << endl;
    cout << "\n\n";
}

void employee::find(string name)
{
    if (empName == name)
    {
        cout << "\nEmployee id: " << empId << endl;
        cout << "Employee name: " << empName << endl;
        cout << "Employee salary: " << empSalary << endl;
        cout << "\n\n";
    }
}

void employee::modify(employee &emp, string v_empName, int ch)
{
    
        ofstream file;
        file.open("9_ass-3.dat", ios::ate | ios::binary);
        
    if (empName == v_empName)
    {
        cout << "Enter id: ";
        cin >> empId;
        cout << "Enter name: ";
        cin >> empName;
        cout << "Enter salary: ";
        cin >> empSalary;
        cout << "\n\n";
        file.seekp(ch);
        file.write((char *)&emp, sizeof(emp));
    }
}

int choice()
{
    int ch;
    cout << "\n1. Add a new record." << endl;
    cout << "2. Modify an existing record." << endl;
    cout << "3. Retrieve and display an entire record for a given name." << endl;
    cout << "4. Generate a complete list of all names, addresses and telephone numbers." << endl;
    cout << "5. End of the computation." << endl;
    cout << "\n Enter your choice: ";
    cin >> ch;
    return ch;
}

int main()
{
    int option;
    do
    {
        cout<<"\n";
        option = choice();
        switch (option)
        {
        case 1:
        {
            // a. Add a new record.

            int id, salary;
            string name;
            ofstream file;
            file.open("9_ass-3.dat", ios::trunc | ios::binary);
            if (!file.is_open())
                cout << "Cannot open the file" << endl;

            cout << "Enter id: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter salary: ";
            cin >> salary;

            employee emp(id, name, salary);
            file.write((char * )&emp, sizeof(emp));
            break;
        }
        case 2:
        {
            //  b. Modify an existing record.

            string name;
            ifstream file;
            file.open("9_ass-3.dat", ios::in | ios::binary);
            if (!file.is_open())
                cout << "Cannot open the file" << endl;

            cout << "Enter your name to find: ";
            cin >> name;
            while (!file.eof())
            {
                employee emp;
                int ch = file.tellg();
                file.read((char *)&emp, sizeof(emp));
                emp.modify(emp, name, ch);
            }
            break;
        }
        case 3:
        {
            //  c. Retrieve and display an entire record for a given name.

            string name;
            ifstream file;
            file.open("9_ass-3.dat", ios::in | ios::binary);
            if (!file.is_open())
                cout << "Cannot open the file" << endl;

            cout << "Enter your name to find: ";
            cin >> name;
            while (!file.eof())
            {
                employee emp;
                file.read((char *)&emp, sizeof(emp));
                emp.find(name);
            }
            break;
        }
        case 4:
        {
            // d. Generate a complete list of all names, addresses and telephone numbers.

            ifstream file;
            file.open("9_ass-3.dat", ios::in | ios::binary);
            if (!file.is_open())
                cout << "Cannot open the file" << endl;
            while (!file.eof())
            {
                employee emp;
                file.read((char *)&emp, sizeof(emp));
                emp.display();
            }
            break;
        }
        default:
        {
            break;
        }
        }
    } while (option != 5);
    cout << "Done :)" << endl;
    return 0;
}
