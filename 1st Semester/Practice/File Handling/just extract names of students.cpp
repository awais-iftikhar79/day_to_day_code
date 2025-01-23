#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ifstream file_to_read("student.txt");
	string line,name;
	if(file_to_read.is_open()){
		cout<<"Student names is file are:"<<endl;
		while(getline(file_to_read,line)){
			size_t name_psoition=line.find("Name  : ");
			if(name_psoition!=string::npos){
				size_t start=name_psoition+8;
				size_t end=line.find(",",start);
				name = line.substr(start,end-start);
				cout<<name<<endl;
			}
		}
		cout<<"Data has been readed sucessfully!"<<endl;
	}else{
		cout<<"Unable to write file without opening\n";
	}
	return 0;
}

