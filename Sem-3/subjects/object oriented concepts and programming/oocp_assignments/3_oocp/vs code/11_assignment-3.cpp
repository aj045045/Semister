/*
 * 11)  WAP to create namespace having function for total_marks. Show its use in
 *      class ‘marks’ of students, display total marks of subjects using namespace.
 */

#include <iostream>
#include<string>
using namespace std;

namespace total_marks
{
    class marks
    {
        string name;
        int total;

    public:
        marks(){};
        marks(string v_name,int totals);
        void total_marks();
    };

    marks::marks(string v_name,int totals)
    {
        name=v_name;
        total=totals;
    }
    void marks:: total_marks()
    {
        
        cout<<"Name of student: "<<name<<endl;
        cout<<"Total marks: "<<total<<endl;
    }
}

using namespace total_marks;
int main()
{
    int maks;
    string name;
    cout<<"Enter name of student:";
    cin>>name;
    cout<<"Enter marks of student: ";
    cin>>maks;
    marks a1(name,maks);
    a1.total_marks();
}
