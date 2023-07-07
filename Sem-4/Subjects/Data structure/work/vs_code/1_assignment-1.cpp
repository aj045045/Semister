
//REVIEW - 1)  Define a structure of book store with appropriate data members and declare nested structure in it as book information.
//              Read the information of book store and display the information in proper format.


#include <iostream>
using namespace std;

struct store
{
    char customerName[20];
    struct date
    {
        int date, month, year;
    } borrowDate, returnDate;
    struct book
    {
        int price;
        char bookName[20], publication[20], author[20];
    } bookInfo;
};

int main()
{
    struct store customer[10];
    int choice = 0, iterator = 0;
    do
    {
        cout << "===========[ Enter the details ]==========" << endl;
        cout << "Customer Name :";
        cin >> customer[iterator].customerName;
        cout << "Borrow Date ( dd mm yy ) :";
        cin >> customer[iterator].borrowDate.date;
        cin >> customer[iterator].borrowDate.month;
        cin >> customer[iterator].borrowDate.year;
        cout << "Return Date ( dd mm yy ) :";
        cin >> customer[iterator].returnDate.date;
        cin >> customer[iterator].returnDate.month;
        cin >> customer[iterator].returnDate.year;
        cout << "Book Name :";
        cin >> customer[iterator].bookInfo.bookName;
        cout << "Book Publication:";
        cin >> customer[iterator].bookInfo.publication;
        cout << "Book Author :";
        cin >> customer[iterator].bookInfo.author;
        cout << "Book Price :";
        cin >> customer[iterator].bookInfo.price;
        cout << "Do you want to enter another book ( for YES[1] ) :";
        cin >> choice;
        (choice == 1) ? iterator++ : choice = 0;
    } while (choice == 1);

    cout << "\n\n===========[ Displaying the data ]=============" << endl;
    for (int i = 0; i <= iterator; i++)
    {
        cout << "Customer Name :" << customer[iterator].customerName << endl;
        cout << "Borrow Date ( dd/mm/yy ) :" << customer[iterator].borrowDate.date << "/" << customer[iterator].borrowDate.month << "/" << customer[iterator].borrowDate.year << endl;
        cout << "Return Date ( dd/mm/yy ) :" << customer[iterator].returnDate.date << "/" << customer[iterator].returnDate.month << "/" << customer[iterator].returnDate.year << endl;
        cout << "Book Name :" << customer[iterator].bookInfo.bookName << endl;
        cout << "Book Publication:" << customer[iterator].bookInfo.publication << endl;
        cout << "Book Author :" << customer[iterator].bookInfo.author << endl;
        cout << "Book Price :" << customer[iterator].bookInfo.price << endl;
    }
    return 0;
}