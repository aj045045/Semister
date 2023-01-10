/*
    5)  Create a class student from which the classes test and sports are derived.
        The class student has the name and rollno of the student. The class test has
        the marks of the internal test and the sports class has the marks of the sports
        test. The class student contains a virtual function display() which are
        implemented in the classes test and sports. Write a program which will take
        relative information and display it using pointer of the base class.
      
       use pointer of base class
                                            student
                                          (name,rollno)
                                    test                 sports        [ Virtual function display() ]
                                (internalMarks)        (sportMarks)          

*/

#include <string>
#include <iostream>
using namespace std;

                                                                        /*
                                                                                Base class student
                                                                        */
class student {
    int rollNo;
    string name;
public:
    student() { rollNo = 0; };
    student(int roll, string nam);
    virtual ~student();
    virtual void display();
};

                                                                         /*
                                                                                test <-- student
                                                                                Derived class test , use student as base class
                                                                         */

class test:public student{
    int internalMarks[6];
public:
    test(int marks[6]);
    void display();
    ~test();
};

                                                                           /*
                                                                                sports <-- student
                                                                                Derived class sports ,use student as the base class
                                                                           */
class sports :public student {
    int sportMarks[3];
public:
    sports(int marks[3]);
    void display();
    ~sports();
};
                                                                           /*
                                                                                Base class student function
                                                                           */
student::student(int roll, string nam)
{
    rollNo = roll;
    name = nam;
}

void student::display()
{
    cout << "Roll number: " << rollNo << "\nName: " << name << endl;
}
student::~student() {
    cout << "Destructor the student class" << endl;
}
                                                                               /*
                                                                                   Derived class test function
                                                                               */

test::test(int marks[6])
{
    for (int i = 0; i < 6; i++)
    {
        internalMarks[i] = marks[i];
    }
}

void test::display()
{
    for (int i = 0; i < 6; i++)
    {
        cout << "Marks of " << i+1 << " subject: " << internalMarks[i] << endl;
    }
}
test::~test() {
    cout << "Destructor the test class" << endl;
}
                                                                                  /*
                                                                                        Derived class sports functions
                                                                                  */
sports::sports(int marks[3])
{
    for (int i = 0; i < 3; i++)
    {
        sportMarks[i] = marks[i];
    }
}

void sports::display()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Marks of " << i + 1 << " subject: " << sportMarks[i] << endl;
    }
}
sports::~sports() {
    cout << "Destructor the student class" << endl;
}
                                                                                    /*
                                                                                            local variables
                                                                                    */
int choice() {
    int ch;
    cout << "Enter your choice" << endl;
    cout << "1. Test marks" << endl;
    cout << "2. Sports marks" << endl;
    cout << "0. Exit" << endl;
    cin >> ch;
    return ch;
}

int main()
{
    int ch;
    do {
        ch = choice();
        switch (ch)
        {
        case 1: {
            int marks[6]{};
            int roll;
            string nam;
            cout << "Enter student details" << endl;
            cout << "Roll number: ";
            cin >> roll;
            cout << "Name: ";
            cin >> nam;
            cout << "Test marks: " << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << "Subject " << i + 1 << " marks: ";
                cin >> marks[i];
            }
            test t1(marks);
            student* ptrStudent=nullptr, s1(roll, nam);
            cout << "\n\n================= OUTPUT =================" << endl;
            s1.display();
            ptrStudent = &t1;
            ptrStudent->display();
            break;
        }
        case 2: {
            int marks[3]{}, roll;
            string nam;
            cout << "Enter student details" << endl;
            cout << "Roll number: ";
            cin >> roll;
            cout << "Name: ";
            cin >> nam;
            cout << "Test marks: " << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << "Subject " << i + 1 << " marks: ";
                cin >> marks[i];
            }
            sports s1(marks);
            student* ptrStudent = nullptr, stu1(roll, nam);
            cout << "\n\n================= OUTPUT =================" << endl;
            stu1.display();
            ptrStudent = &s1;
            ptrStudent->display();
            break;
        }
        case 3: {
            exit(0);
        }
        default: {
            cout << "ERRORS" << endl;
            cout << "Enter valid option" << endl;
        }
        }

    } while (ch != 0);
             
}