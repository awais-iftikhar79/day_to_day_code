#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream out_file("message.txt");
    if (out_file.is_open())
    {
        out_file << "Welcome to C++ Programing !" << endl;
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    out_file.close();

    ifstream in_file("message.txt");
    if (in_file.is_open())
    {
        string line;
        cout << "Reading context in file is : ";
        getline(in_file, line);
        cout << line << endl;
        in_file.close();
    }

    return 0;
}