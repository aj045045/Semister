/*
4)  An educational institution wishes to maintain a database of its employees.
    The database is divided into a number of classes whose hierarchical
    relationships are shown in fig-1. The figure also shows the minimum
    information required for each class. Specify all the classes and define function
    to create the database and retrieve individual information as and when
    required. Write parameterized constructor for each class in the hierarchy.
            
                                STAFF
                              (code,name)

            TEACHER              TYPIST         OFFICER
        (subject,publication),   (speed),       (grade)

                     REGULAR       CASUAL
                                  (daily_wages)
*/

#include <iostream>
#include <string>
using namespace std;

                                                                // Base class staff
class staff {
    int code;
    string name;
public:
    staff(){code = 0;};
    staff(int c, string n);
    void print();
};
                                                                            
                                                                    /*
                                                                        teacher <-- staff
                                                                        Derived class teacher ,use base class staff
                                                                    */
class teacher:public staff {
    string subject;
    string publication;
public:
    teacher() {};
    teacher(string s, string p, int c, string n);
    void print();
};

                                                                   /*
                                                                        typist <-- staff
                                                                        Derived class typist ,use base class 
                                                                   */
class typist :public staff {
    int speed;
public:
    typist(){speed = 0;};
    typist(int s, int c, string n);
    void print();
};

                                                                  /*
                                                                        casual <-- typist
                                                                         Derived class casual ,use base class typist
                                                                  */
class casual:public typist{
    int dailyWages;
public:
    casual(int d, int s, int c, string n);
    void print();
};

                                                                 /*
                                                                        regular <-- typist
                                                                        Derived class regular ,use base class typist
                                                                 */
class regular :public typist {
    int wages;
public:
    regular(int no, int s, int c, string n);
    void print();
};



                                                                /*
                                                                        officer <-- staff
                                                                        Derived class officer, use base class staff
                                                                */ 
class officer :public staff {
    int grade;
public:
    officer(int c, int co, string n);
    void print();
};


                                                                                // class staff function 
staff::staff(int c, string n)
{
    code = c;
    name = n;
}

void staff::print()
{
    cout << "Code: " << code << "\nName: " << name << endl;
}

                                                                                  // class teacher function 
teacher::teacher(string s, string p, int c, string n):staff(c,n)
{
    subject = s;
    publication = p;
}

void teacher::print()
{
    staff::print();
    cout << "Subject: " << subject << "\nPublication: " << publication << endl;
}

                                                                                    // class typist function
typist::typist(int s, int c, string n):staff(c,n)
{
    speed = s;
}

void typist::print()
{
    staff::print();
    cout << "Typing speed: " << speed << endl;
}

                                                                                    // class casual function
casual::casual(int d, int s, int c, string n):typist(s,c,n)
{
    dailyWages = d;
}

void casual::print()
{
    typist::print();
    cout << "Daily wages: " << dailyWages << endl;
}

                                                                                // class regular fuction
regular::regular(int no, int s, int c, string n):typist(s,c,n)
{
    wages = no;
}
void regular::print()
{
    typist::print();
    cout << "Normal speed: " << wages << endl;
}

                                                                                  // class officer function
officer::officer(int c, int co, string n) :staff(co, n)
{
    grade = c;
}
void officer::print()
{
    staff::print();
    cout << "Grade: " << grade << endl;
}

                                                                                    // Local functions
int choice()
{
    int ch;
    cout << "Enter your choice:" << endl;
    cout << "1. Teacher" << endl;
    cout << "2. Officer" << endl;
    cout << "3. Typist" << endl;
    cout << "0. Exit" << endl;
    cin >> ch;
    if (ch == 3)
    {
        cout << "4. Regular typist: " << endl;
        cout << "5. Casual typist: " << endl;
        cin >> ch;
    }
     return ch; 
}


int main()
{
    int ch;
   do
    {
        cout << "\n" << endl;
        ch = choice();
    switch (ch)
    {
    case 0: {
        exit(0);
        break;
    }
    case 1:
        {
        int c; 
        string p,n,s;

        cout << "Enter teachers details: " << endl;
        cout << "Staff code: ";
        cin >> c;
        cout << "Name: ";
        cin >> n;
        cout << "Subject: ";
        cin >> s;
        cout << "Publication: ";
        cin >> p;
        teacher t1(s, p, c, n);
        cout << "\n\n============== OUTPUT ===========" << endl;
        t1.print();
            break;
        }
    case 2:
        {
        int c, co;
        string n;

        cout << "Enter officer details: " << endl;
        cout << "Staff code: ";
        cin >> co;
        cout << "Name: ";
        cin >> n;
        cout << "Grade: ";
        cin >> c;
        cout << "\n\n============== OUTPUT ===========" << endl;
        officer of1(c, co, n);
        of1.print();
        break;
        }
    case 4:
        {
        int no, s, c;
        string n;
        
        cout << "Enter regular typist details: " << endl;
        cout << "Name: ";
        cin >> n;
        cout << "Speed: ";
        cin >> s;
        cout << "Staff code: ";
        cin >> c;
        cout << "Wages: ";
        cin >> no;
        cout << "\n\n============== OUTPUT ===========" << endl;
        regular r1(no, s, c, n);
        r1.print();
        break;
        }
    case 5:
        {
        int d, s, c;
        string n;

        cout << "Enter casual typist details: " << endl;
        cout << "Name: ";
        cin >> n;
        cout << "Speed: ";
        cin >> s;
        cout << "Staff code: ";
        cin >> c;
        cout << "Wages: ";
        cin >> d;
        cout << "\n\n============== OUTPUT ===========" << endl;
        casual c1( d,  s,  c,  n);
        c1.print();
        break;
        }
    default:
    {
        cout << " ERROR " << endl;
        cout << "Enter valid options" << endl;
    }
    }

   } while (ch != 0);
   return 0;
}
