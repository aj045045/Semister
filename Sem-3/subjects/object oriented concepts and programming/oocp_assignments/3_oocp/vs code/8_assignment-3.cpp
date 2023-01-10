/*
*   8)  Define a class Result which contains the result of written test. It should take
*       list from a file and display on the screen such that at a time only ten
*       candidates information is printed on the screen.
*/
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class result
{
    int rollNo;
    char name[30];
    int marks[3];
public:
    void readResults();
    void displayResults();
};
void result::readResults()
{
    cout << "\n Enter roll no.: ";
    cin >> rollNo;
    cout << " Enter name: ";
    cin >> name;
    cout << " Enter marks " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Marks " << i + 1 << ": ";
        cin >> marks[i];
    }
    cout << "\n";
}
void result::displayResults()
{
    cout << "\n Display roll no.: " << rollNo << endl;
    cout << " Display name: " << name << endl;
    cout << " Display marks " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " Marks of " << i + 1 << " subject: " << marks[i] << endl;
    }
    cout << "\n";
}
int main()
{
    result res[10];
    ofstream file;
    file.open("8_assi-3.dat", ios::out | ios::binary | ios::trunc);
    if (!file.is_open())
        cout << "Files cannot open" << endl;
    for (int i = 0; i < 10; i++)
    {
        res[i].readResults();
        file.write((char * )&res[i], sizeof(res[i]));
    }
    file.close();
                                                                            // Printing the data from binary file
    result res1[10];
    ifstream files;
    files.open("8_assi-3.dat", ios::in | ios::binary);
    if (!files.is_open())
        cout << "Files cannot open" << endl;
    for (int i = 0; i < 10; i++)
    {
        files.read((char *)&res1[i], sizeof(res1[i]));
        res1[i].displayResults();
    }
    files.close();
    return 0;
}