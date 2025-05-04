#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ofstream outfile;

    outfile.open("output.txt");

    outfile << "My name is Awais Iftikhar " << endl;
    outfile << "I love Cricket" << endl;

    outfile.close();

    cout << "Data succesfully written to file!" << endl;

    return 0;
}