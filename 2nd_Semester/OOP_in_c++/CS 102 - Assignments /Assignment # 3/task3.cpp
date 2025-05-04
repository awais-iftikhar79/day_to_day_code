#include <iostream>
#include <fstream>
using namespace std;

int main(){

fstream file;

file.open("log.txt", ios::app);

file<<"USA detonated bombs on Hiroshima and Nagasaki"<<endl;
file<<"Hitler died towards the end of the war"<<endl;

cout<<"Data succesfully written to file!"<<endl;

return 0;
}