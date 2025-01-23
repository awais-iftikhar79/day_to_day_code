#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string line,name,age;
	ifstream file_to_read("student.txt");
	if(file_to_read.is_open()){
		while(getline(file_to_read,line)){
			size_t name_position=line.find("Name  : ");
			size_t age_position=line.find("Age : ");
			if(name_position!=string::npos && age_position!=string::npos){
				size_t start=name_position+9;
				size_t name_end=line.find(",",start);
				name=line.substr(start,name_end-start);
				size_t age_start=age_position+6;
				size_t age_end=line.find(" ",age_start);
				if(age_end==string::npos ){
					age_end=line.length();
				}
				age=line.substr(age_start,age_end-age_start); 
				cout<<"Names : "<<name<<endl;
			cout<<"Age : "<<age<<endl;
			cout<<endl;
			}
			}
			 
		}else{
				cout<<"Unable to read file!"<<endl;
	}
	
	return 0;
}
