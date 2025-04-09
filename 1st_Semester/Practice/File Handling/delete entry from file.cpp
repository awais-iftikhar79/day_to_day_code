#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string names[50];
	int age[50];
	int stu_count=0;
	string name_to_delete,line,age_str,name;
	bool found=false;
	ifstream file_to_read("Student names and ages.txt");
	if(file_to_read.is_open()){
		while(getline(file_to_read,line)){
			size_t space_pos=line.rfind(" ");
			if(space_pos!=string::npos){
				name=line.substr(0,space_pos);
				age_str=line.substr(space_pos+1);
				int age1=stoi(age_str); 
				names[stu_count]=name;
				age[stu_count]=age1;
			}
			stu_count++;
		}
	}else{
		cout<<"Unable to read"<<endl;
		 return 1;
	}
	file_to_read.close();
	cout<<"Enter name of student of which you want to delete data"<<endl;
	getline(cin,name_to_delete);
	for(int i=0;i<stu_count;i++){
		if(names[i]==name_to_delete){
			found=true;
			for(int j=i;j<stu_count-1;j++){
				names[j]=names[j+1];
				age[j]=age[j+1];
			}
			cout<<"You have delete entery sucessfully";
			stu_count--;
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