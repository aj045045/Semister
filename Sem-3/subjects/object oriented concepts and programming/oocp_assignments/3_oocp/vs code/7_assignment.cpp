/*
 *   7)  Write a program to create a file student to store name and marks of 5 students and then display them.
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class student
{
    int id;
    string name;
    int marks[5];

public:
    student(){};
    void inputMarks();
    void outputMarks();
};
// TODO :class student function using scope resolution operator
void student::inputMarks()
{
    cout << "Enter student id: ";
    cin >> id;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter  subject marks:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];
    }
}
void student::outputMarks()
{
    cout << "\n\nEnter student id: " << id << endl;
    cout << "Enter student name: " << name << endl;
    cout << "Enter  subject marks:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Subject " << i + 1 << ": " << marks[i] << endl;
    }
}
int main()
{
    int n;
    student s[10];
    cout << "Enter how many student data you want to enter" << endl;
    cin >> n;
    ofstream file;
    file.open("7_assi.dat", ios::out | ios::binary | ios::trunc);
    if (!file.is_open())
    {
        cout << "File cannot be open" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        s[i].inputMarks();
        file.write((char * ) &s[i], sizeof(s[i]));
        if (file.fail())
            cout << "File write failed";
    }
    file.close();
    cout << "==========PRINTING FILES =====================" << endl;
    ifstream files;
    files.open("7_assi.dat", ios::in | ios::binary);
    student s2[10];
    if (!files.is_open())
    {
        cout << "File cannot be open" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        files.read((char *)&s2[i], sizeof(s2[i]));
        s2[i].outputMarks();
        if (files.fail())
            cout << "File read failed";
    }
    return 0;
}