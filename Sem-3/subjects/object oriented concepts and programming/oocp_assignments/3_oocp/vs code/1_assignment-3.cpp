/*
 * 1)  Write a program to create base class Book having int id and string name as data members and respective
 *     functionality, show following types of inheritance and display the details of each kind of books, also
 *     calculate the total no of each type of books in proper format.
 *     Simple inheritance with derived class Sales
 *     Hierarchical inheritance with derived classes academics and thrillers
 *     Show use of constructor and destructor in above examples of inheritance.
 */
#include <string>
#include <iostream>
using namespace std;

class book
{
    int bookId;
    string bookName;

public:
    book(){};
    book(int id, string name);
    void print();
    ~book();
};
book::~book()
    {
        cout<<"Destructor is called: book"<<endl;
    }
class sales : public book
{
    int salesId;
    string customerName;

public:
    sales(){};
    sales(int sid, string sname, int bid, string bname);
    void print();
    ~sales();
};
sales::~sales()
{
    cout<<"Destructor is called: sales"<<endl;
}
sales::sales(int sid, string sname, int bid, string bname) : book(bid, bname)
{
    salesId = sid;
    customerName = sname;
}

class academics : public sales
{
    int academicsId;
    string academicsName;

public:
    academics(int aid, string aname, int sid, string sname, int bid, string bname);
    void print();
    ~academics();
};
academics::~academics()
    {
        cout<<"Destructor is called: academics"<<endl;
    }


academics::academics(int aid, string aname, int sid, string sname, int bid, string bname) : sales(sid, sname, bid, bname)
{
    academicsId = aid;
    academicsName = aname;
}

class thillers : public sales
{
    int thillersId;
    string thillersName;

public:
    thillers(int tid, string tname, int sid, string sname, int bid, string bname);
    void print();
    ~thillers();
};
thillers::~thillers()
    { 
        cout<<"Destructor is called: thillers"<<endl;
    }

thillers::thillers(int tid, string tname, int sid, string sname, int bid, string bname) : sales(sid, sname, bid, bname)
{
    thillersId = tid;
    thillersName = tname;
}

int main()
{
    int choice;

    cout << "What do you want to enter Academics(0) or Thiller(1)" << endl;
    cout << "Enter your choice :";
    cin >> choice;
    switch (choice)
    {
    case 0:
    {
        int b, s, a;
        string bn, sn, an;
        cout << "Enter book  Details" << endl;
        cout << "ID :";
        cin >> b;
        cout << "Name:";
        cin >> bn;
        cout << "\nEnter Sales  Detail" << endl;
        cout << "ID :";
        cin >> s;
        cout << "Customer Name:";
        cin >> sn;
        cout << "\nEnter Academics  Details" << endl;
        cout << "ID :";
        cin >> a;
        cout << "Name:";
        cin >> an;

        academics a1(a, an, s, sn, b, bn);
        system("cls");
        a1.print();
        break;
    }
    case 1:
    {
        int b, s, t;
        string bn, sn, tn;
        cout << "Enter book  Details" << endl;
        cout << "ID :";
        cin >> b;
        cout << "Name:";
        cin >> bn;
        cout << "\nEnter Sales  Detail" << endl;
        cout << "ID :";
        cin >> s;
        cout << "Customer Name:";
        cin >> sn;
        cout << "\nEnter Thillers  Details" << endl;
        cout << "ID :";
        cin >> t;
        cout << "Name:";
        cin >> tn;

        thillers t1(b, bn, s, sn, t, tn);
        system("cls");
        t1.print();
        break;
    }
    default:
    {
        cout << "Enter wrong option:" << endl;
    }
    }
}

book::book(int bid, string bname)
{
    bookId = bid;
    bookName = bname;
}

void book::print()
{
    cout << "\n\nID :" << bookId << "\nName :" << bookName << endl;
}
void sales::print()
{
    book::print();
    cout << "ID :" << salesId << "\nCustomer Name :" << customerName << endl;
}
void academics::print()
{
    sales::print();
    cout << "ID :" << academicsId << "\nName :" << academicsName << endl;
}
void thillers::print()
{
    sales::print();
    cout << "ID :" << thillersId << "\nName :" << thillersName << endl;
}
