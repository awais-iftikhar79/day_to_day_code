#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string line;
	fstream file_to_write("Student names and ages.txt",ios::in|ios::out);
	if(!file_to_write.is_open()){
		cout<<"Unable to open file "<<endl;
		return 0;	
	}
	while(getline(file_to_write,line)){
		if(line.find("Muhammad")!=string::npos){
			file_to_write.seekp(file_to_write.tellg()-line.length());
			file_to_write<<"Ali Bhai !";
		}
	}
	return 0;
}