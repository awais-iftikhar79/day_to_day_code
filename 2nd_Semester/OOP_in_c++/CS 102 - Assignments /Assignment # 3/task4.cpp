#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream infile;
    fstream outfile;

    string line;

    outfile.open("truncate.txt");

    outfile << "My name is Awais Iftikhar" << endl;

    outfile.close();

    infile.open("truncate.txt");

    cout << "File contents: ";
    while (getline(infile, line))
    {
        cout << line << endl;
    }

    infile.close();

    outfile.open("truncate.txt", ios::out | ios::trunc);

    outfile.close();

    infile.open("truncate.txt");

    cout << "Updated file contents: ";
    while (getline(infile, line))
    {
        cout << line << endl;
    }

    infile.close();
}