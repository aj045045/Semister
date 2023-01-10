/*
*  2)  Write a program to create student having data members (rollno, name, stream) as base
*      class. Derive class subject with marks of 5 subjects and apply respective
*      functionality. Calculate final result and display details of each student from
*      derived class. (multilevel inheritance).
*/

#include <iostream>
#include <string>
using namespace std;

                                                                                                    // Details of Base class subject
class subj
{
    int sub1, sub2, sub3, sub4, sub5;
    int percent;
public:
    subj(){};
    subj(int s1, int s2, int s3, int s4, int s5);
    void print();
    void cal();
    ~subj();
};
subj::~subj()
{
    cout<<"Desturctor is called: subject";
}
                                                                                                    // Details of Detived class students
class stud : public subj
{
    int rollNo;
    string name;
    string stream;

public:
    stud(int r, string n, string s, int s1, int s2, int s3, int s4, int s5);
    void print();
    ~stud();
};
stud::~stud()
    {
        cout<<"Destructor is called: students"<<endl;
    }
stud::stud(int r, string n, string s, int s1, int s2, int s3, int s4, int s5) : subj(s1, s2, s3, s4, s5)
{
    rollNo = r;
    name = n;
    stream = s;
}

subj::subj(int s1, int s2, int s3, int s4, int s5)
{
    sub1 = s1;
    sub2 = s2;
    sub3 = s3;
    sub4 = s4;
    sub5 = s5;
}

void subj::print()
{
    cout << "=============================" << endl;
    cout << "SUBJECT" << endl;
    cout << "=============================" << endl;
    cout << sub1 << endl;
    cout << sub2 << endl;
    cout << sub3 << endl;
    cout << sub4 << endl;
    cout << sub5 << endl;
        cout<<"Percentage :"<<percent<<endl;
}
void stud::print()
{
    subj::print();
    cout << "\n===========================================" << endl;
    cout << "STUDENTS" << endl;
    cout << "===========================================" << endl;
    cout << "Rollno :" << rollNo << endl;
    cout << "Name :" << name << endl;
    cout << "Stream :" << stream << endl;
}

void subj::cal()
{
    int total=sub1+sub2+sub3+sub4+sub5;
    percent=(total*100)/500;
}


int main()
{
    int r, s1, s2, s3, s4, s5;
    string n, s;
    cout << "Enter the details" << endl;
    cout << "Rollno :";
    cin >> r;
    cout << "Name :";
    cin >> n;
    cout << "Stream :";
    cin >> s;
    cout << "Subject 1 :";
    cin >> s1;
    cout << "Subject 2 :";
    cin >> s2;
    cout << "Subject 3 :";
    cin >> s3;
    cout << "Subject 4 :";
    cin >> s4;
    cout << "Subject 5 :";
    cin >> s5;

    stud stu1(r, n, s, s1, s2, s3, s4, s5);
    stu1.cal();
    stu1.print();
    return 0;
}
