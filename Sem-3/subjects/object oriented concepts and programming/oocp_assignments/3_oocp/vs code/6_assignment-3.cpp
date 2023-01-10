/*
    *   6) Write a Program to perform following operation on text file :
    *   
    *   11.1) write content in a text file
    *   11.2) read content from file
    *   11.3) count no of word and no of lines in a file
    *   11.4) copy contents of one file to another file
*/
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
/*
        Local function
*/
int choice()
{
    int ch;
    cout << "\n1) Write content in a text file" << endl;
    cout << "2) Read content from file" << endl;
    cout << "3) Count no of word and no of lines in a file" << endl;
    cout << "4) Copy contents of one file to another file" << endl;
    cout << "5) Exit" << endl;
    cin >> ch;
    return ch;
}
int main()
{
    int option;
    do
    {
        option = choice();
        switch (option)
        {
        case 1:
        {
            char ch;
            ofstream file("6_assi-3.txt", ios::trunc);
            cout<<"Enter the text to store in files"<<endl;
            while (true)
            {
                cin.get(ch);
                if (ch == '$') break;
                file << ch;
            }
            file.close();
            break;
        }
        case 2:
        {
            char ch;
            ifstream file("6_assi-3.txt");
            while (!file.eof())
            {
                file.unsetf(ios::skipws);
                file >> ch;
                cout << ch;
            }
            file.close();
            break;
        }
        case 3:
        {
            string line;
            int numLine = 0, numWords = 0;
            char ch;
            ifstream file("6_assi-3.txt");
        do{
                file.get(ch);
                if (ch == ' ')
                {
                    numWords++;
                }
            } while (!file.eof());
            file.close();
            ifstream files("6_assi-3.txt");
            while (!getline(files, line).eof())
            {
                files.unsetf(ios::skipws);
                numLine++;
            }
            files.close();
            cout << "\n\nNumber of words: " << numWords << "\nNumber of line: " << numLine << endl;
            break;
        }
        case 4:
        {
            string s;
            ofstream file1("copyFile.txt");
            ifstream file2("6_assi-3.txt");
            cout<<"Copying a file to other file";
            do{
                file1 << s;
                cout<<s<<endl;
            } while (!getline(file2, s).eof());
            file2.close();
            file1.close();
            break;
        }
        case 5:{
            exit(0);
            break;
        }
        default:
        {
            cout<<"Please enter a valid option"<<endl;
        }
        }
    } while (option!=5);
    return 0;
}