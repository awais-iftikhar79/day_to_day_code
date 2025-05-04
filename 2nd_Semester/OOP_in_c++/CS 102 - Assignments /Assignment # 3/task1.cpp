#include <iostream>
#include <fstream>
using namespace std;

int main(){

ifstream infile;

infile.open("example.txt");

if (!infile){
    cout<<"Error: File not found!"<<endl;

    return 1;
}

string line;

cout<<"File contents: "<<endl;
while(getline (infile, line)){
    cout<<line<<endl;
}

infile.close();

return 0;
}