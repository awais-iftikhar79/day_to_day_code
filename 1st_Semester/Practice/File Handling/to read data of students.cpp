#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ifstream file_to_read("student.txt");
	string line;
	if(file_to_read.is_open()){
		while(getline(file_to_read,line)){
			cout<<line<<endl;
		}
		cout<<"Data has been readed sucessfully!"<<endl;
	}else{
		cout<<"Unable to write file without opening\n";
	}
	return 0;
}

