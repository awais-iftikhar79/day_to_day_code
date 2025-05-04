#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outfile;

    outfile.open("append_end.txt", ios::ate | ios::app);

    
    outfile << " New entry added at the end!"<<endl;

    outfile.close();

    ifstream infile;

    infile.open("append_end.txt");

    string line;

    cout << "File contents: ";
    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();

    return 0;
}
