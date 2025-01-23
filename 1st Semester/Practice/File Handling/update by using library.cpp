#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	string names[50];
	int age[50];
	int stu_count=0;
	string name_to_update,line,age_str,name;
	bool found=false;
	ifstream file_to_read("Student names and ages.txt");
	if(file_to_read.is_open()){
		while(getline(file_to_read,line)){
			stringstream str(line);
			file_to_read>>name>>age_str;
				int age1=stoi(age_str); 
				names[stu_count]=name;
				age[stu_count]=age1;
			}
			stu_count++;
		}else{
			cout<<"Enable to to read file"<<endl;
			return 1;
		}
	file_to_read.close();
	cout<<"Enter name of which you want to update age"<<endl;
	getline(cin,name_to_update);
	for(int i=0;i<stu_count;i++){
		if(name_to_update==names[i]){
			cout<<"Student found"<<endl;
			cout<<"Name of student is "<<names[i]<<" and age is "<<age[i]<<endl;
			cout<<"Enter age of "<<names[i]<<endl;
			cin>>age[i];
			found=true;
			cout<<names[i]<<"'s age change sucessfully!"<<endl;
			break;	
		}
	}
	if(!found){
		cout<<"Student not found like this name"<<endl;
		return 1;
	}
	ofstream file_to_write("Student names and ages.txt");
	if(file_to_write.is_open()){
	for(int i=0;i<stu_count;i++){
		file_to_write<<names[i]<<" "<<age[i]<<endl;
	}
	file_to_write.close();
	}else{
		cout<<"File not found"<<endl;
	}
	
	return 0;
}