#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ifstream infile;
    ofstream outfile;

    outfile.open("data.txt");

    outfile << "Life is all about learning and growing every day" << endl;

    outfile.close();

    infile.open("data.txt");

    infile.seekg(10, ios::beg);

    string line;

    cout << "File contents from 10th letter: ";
    while (getline(infile, line))
    {
        cout << line;
    }

    infile.close();

    return 0;
}
