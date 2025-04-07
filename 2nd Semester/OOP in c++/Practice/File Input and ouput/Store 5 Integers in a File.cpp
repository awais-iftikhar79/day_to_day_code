#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream out_file("numbers.txt");
    if (out_file.is_open())
    {
        int i = 1;
        while (i <= 5)
        {

            int n;
            cout << "Enter  number : " << endl;
            cin >> n;
            out_file << n << " ";
            i++;
        }
        out_file.close();
    }
    else
    {
        cout << "Unable to open file " << endl;
    }
    ifstream in_file("numbers.txt");
    if (in_file.is_open())
    {
        string line;
        cout << "Reading context in file : ";
        getline(in_file, line);
        cout << line << endl;
        in_file.close();
    }
    else
    {
        cout << "Unable to read file" << endl;
    }

    return 0;
}