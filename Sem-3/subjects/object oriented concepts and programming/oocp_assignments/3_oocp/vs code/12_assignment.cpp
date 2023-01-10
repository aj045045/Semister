/*
 * 12) Write a program to define a vector and use it for student class to store and display information about student (Use STL).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class student
{
private:
    int rollNumber;
    float totalMarks;

public:
    student() {}
    student(int v_roll, float v_marks);
    void operator=(student v_stud);
    bool operator<(student v_stud);
    friend ostream &operator<<(ostream &v_out,student &v_stud);
};

student::student(int v_roll, float v_marks)
{
    rollNumber = v_roll;
    totalMarks = v_marks;
}
void student::operator=(student v_stud)
{
    rollNumber = v_stud.rollNumber;
    totalMarks = v_stud.totalMarks;
}
bool  student::operator<(student v_stud)
{
    return (totalMarks < v_stud.totalMarks);
}

ostream &operator<<(ostream &v_out, student &v_stud)
{
    v_out << "The mark of roll number " << v_stud.rollNumber << " is " << v_stud.totalMarks;
    return v_out;
}

int main()
{
    vector<student> studentMarks;
    float marks;
    int i = 0;
    for (;;)
    {
        cout << "Enter the mark for roll number " << i + 1 << " Enter -1 to stop :";
        cin >> marks;
        if (marks == -1)
            break;
        studentMarks.push_back(student(i + 1, marks));
        ++i;
    }
    cout << "The size of studentMarks is " << studentMarks.size() << endl;
    vector<student>::iterator index;
    sort(studentMarks.begin(), studentMarks.end());
    for (index = studentMarks.begin(); index < studentMarks.end();++index)
        cout << *index << endl;
    return 0;
}