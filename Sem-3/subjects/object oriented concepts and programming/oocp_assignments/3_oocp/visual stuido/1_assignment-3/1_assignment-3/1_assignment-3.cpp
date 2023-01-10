/*
1)  Write a program to create base class Book having int id and char name as data members and respective 
    functionality, show following types of inheritanceand display the details of each kind of books, also 
    calculate the total no of each type of books in proper format.
    Simple inheritance with derived class Sales
    Hierarchical inheritance with derived classes academics and thrillers
    Show use of constructor and destructor in above examples of inheritance.
*/
#include <iostream>
using namespace std;

class book {
    int bookId;
    char bookName[50];
public:
    book(){};
    book(int id, char name[50]);
    void print();
};

class sales:public book {
    int salesId;
    char customerName[50];
public:
    sales(){};
    sales(int sid, char sname[50], int bid, char bname[50]) :book(bid, bname)
{
    salesId = sid;
    this->customerName[50] = sname[50];
}
    void print();
};

class academics :public sales {
    int academicsId;
    char academicsName[30];
public:
    academics(int aid, char aname[30], int sid, char sname[30], int bid, char bname[30]) :sales(sid, sname, bid, bname)
{
    academicsId = aid;
    academicsName[50] = aname[50];
}
    void print();
};

class thillers :public sales {
    int thillersId;
    char thillersName[30];
public:
thillers(int tid, char tname[30], int sid, char sname[30], int bid, char bname[30]) :sales(sid, sname, bid, bname)
{
    thillersId = tid;
    this->thillersName[30] = tname[30];
}
    void print();
};

int main()
{
    int b, s, a;
    char bn[30], sn[30], an[30];
    cout << "Enter book  Details" << endl;
    cout << "ID :" << endl;
    cin >> b;
    cout << "Name:" << endl;
    cin >> bn;
    cout << "Enter Sales  Detail" << endl;    
    cout << "ID :" << endl;
    cin >> s;
    cout << "Name:" << endl;
    cin >> sn;
    cout << "Enter Academics  Details" << endl;    
    cout << "ID :" << endl;
    cin >> a;
    cout << "Name:" << endl;
    cin >> an;

    academics a1(a,an,s,sn,b,bn);
    a1.print();
    /*cout << "==================================" << endl;
    cout << "Enter book  Details" << endl;
    cout << "ID :" << endl;
    cin >> b;
    cout << "Name:" << endl;
    cin >> bn;
    cout << "Enter Sales  Detail" << endl;
    cout << "ID :" << endl;
    cin >> s;
    cout << "Name:" << endl;
    cin >> sn;
    cout << "Enter Thillers  Details" << endl;
    cout << "ID :" << endl;
    cin >> t;
    cout << "Name:" << endl;
    cin >> tn;
    */

    //thillers t1(b,bn,s,sn,t,tn);


}

book::book(int bid, char bname[30])
{
    bookId = bid;
    this->bookName[30] = bname[30];
}



void book::print()
{
    cout << "======================================"<<endl;
    cout << "BOOKS " << endl;
    cout << "======================================" << endl;
    cout << "ID :" << bookId << "Name :" << bookName << endl;
}
void sales::print()
{
    book::print();
    cout << "======================================" << endl;
    cout << "SALES " << endl;
    cout << "======================================" << endl;
    cout << "ID :" << salesId << "Customer Name :" << customerName << endl;
}
void academics::print()
{
    sales::print();
    cout << "======================================" << endl;
    cout << "ACADEMICS " << endl;
    cout << "======================================" << endl;
    cout << "ID :" << academicsId << "Name :" << academicsName << endl;
}
void thillers::print()
{
    sales::print();
    cout << "======================================" << endl;
    cout << "THILLERS " << endl;
    cout << "======================================" << endl;
    cout << "ID :" << thillersId << "Name" << thillersName << endl;
}
