/*
*  10) Write a program that stores and displays the records of the customer from a
*      file the following information for account of the customer is to be stored.
*      Account no, account type, name, old balance, new balance, last payment, date of last payment.
*      Also display the current account status by comparing current payment and previous balance.
*      Also calculate the current balance by subtracting the current payment from the previous balance.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class account
{
    int accountNo;
    string type;
    string name;
    int oldBalance;
    int newBalance;
    int lastPayment;
    int dateOfLastPayment;

public:
    account() { accountNo = 0;   oldBalance = 0;     lastPayment = 0;      dateOfLastPayment = 0; }
    account(int v_accountNo, string v_type, string v_name, int v_oldBalance);
    void transaction(account &acc,int acc_no, int pos);
    void customerStatus(int acc_no);
};

account::account(int v_accountNo, string v_type, string v_name, int v_oldBalance)
{
    accountNo = v_accountNo;
    type = v_type;
    name = v_name;
    oldBalance = v_oldBalance;
    newBalance = v_oldBalance;
    lastPayment=0;
    dateOfLastPayment=0;
}

void account::customerStatus(int acc_no)
{
    if ( accountNo == acc_no)
    {
    cout << "\n\t\tStatus of account" << endl;
    cout << "Account no: " << accountNo << endl;
    cout << "Type of account: " << type << endl;
    cout << "Customer name: " << name << endl;
    cout << "Old balance: " << oldBalance << endl;
    cout << "New balance: " << newBalance << endl;
    cout << "Last payment: " << lastPayment << endl;
    cout << "Date of last payment: " << dateOfLastPayment << endl;
    }
}

void account::transaction(account &acc,int acc_no, int pos)
{

    ofstream outFile;
    outFile.open("10_assi-3.dat", ios::out | ios::binary);
    if (accountNo == acc_no)
    {
        cout << "Enter payment amount and payment date" << endl;
        cout << "Amount: ";
        cin >> lastPayment;
        cout << "Date: ";
        cin >> dateOfLastPayment;
        oldBalance = newBalance;
        newBalance = oldBalance - lastPayment;
        outFile.seekp(pos);
        outFile.write((char*)&acc, sizeof(acc));
        outFile.close();
    }
}

int choice()
{
    int ch;
    cout << "1. opening a account" << endl;
    cout << "2. Transation " << endl;
    cout << "3. Account status " << endl;
    cout << "4. exit" << endl;
    cout << "\n Enter your choice: ";
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
        case 1:
        {
            ofstream bank;
            bank.open("10_assi-3.dat", ios::out | ios::binary);
            if (!bank.is_open())
            {
                cout << "File cannot be open for storing purpose:" << endl;
            }

            string type, name;
            int No = 0, old = 0;

            cout << "Enter details for creating a account in our bank" << endl;
            cout << "Account no: ";
            cin >> No;
            cout << "Type of account: ";
            cin >> type;
            cout << "Customer name: "; cin >> name;
            cout << "Creadited amount: "; cin >> old;
            account a1(No, type, name, old);
            bank.write((char*)&a1, sizeof(a1));
            bank.close();
            break;
        }
        case 2:
        {
            int acc_no;
            cout << "Account No:" << endl;
            cin >> acc_no;
            ifstream inFile;
            inFile.open("10_assi-3.dat", ios::in | ios::binary);
            account a1;
            while (!inFile.eof())
            {
                int pos = inFile.tellg();
                inFile.read((char*)&a1, sizeof(a1));
                a1.transaction(a1,acc_no, pos);
            }

            break;
        }
        case 3:
        {
            int acc_no;
            cout << "Account No:" << endl;
            cin >> acc_no;
            ifstream inFile;
            inFile.open("10_assi-3.dat", ios::in | ios::binary);
            account a1;
            while (!inFile.eof())
            {
                inFile.read((char*)&a1, sizeof(a1));
                a1.customerStatus(acc_no);
            }
            inFile.close();
            break;
        }
        case 4:{
            exit(0);
        }
        default: {
            cout << "Enter correct option" << endl;
            break;
        }
        }
    } while (ch != 4);


}