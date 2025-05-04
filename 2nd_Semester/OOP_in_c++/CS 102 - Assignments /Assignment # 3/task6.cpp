#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ofstream outfile;
    ifstream infile;

    outfile.open("write_test.txt");

    outfile << "The Smart Eco City Simulator is running perfectly" << endl;

    outfile.seekp(5, ios::beg);
    outfile << "This is inserted";

    outfile.close();

    string line;

    infile.open("write_test.txt");

    cout << "File contents: ";
    while (getline(infile, line))
    {
        cout << line;
    }

    infile.close();

    return 0;
}
