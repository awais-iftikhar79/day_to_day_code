#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const int max_stu=100;
void menu(){
	
	cout<<"---Student Managment System---"<<endl;
	cout<<"1.Add Student ((Press 1)"<<endl
		<<"2.Display All Students (Press 2)"<<endl
		<<"3.Search Student By Roll Number (Press 3)"<<endl
		<<"4.Exit (Press 4)"<<endl;
		
}
string grade(float percentage) {
    if (percentage >= 90)
        return "A";
    else if (percentage >= 80)
        return "B";
    else if (percentage >= 70)
        return "C";
    else if (percentage >= 60)
        return "D";
    else
        return "F";
}
void save_To_file(string names[],int roll_no[],int marks_1[],int marks_2[],int marks_3[],int marks_4[],int marks_5[],int &count){
	fstream file("Student.txt",ios::out);
	if(file.is_open()){
		for(int i=0;i<=count;i++){
			float total_marks=marks_1[count]+marks_2[count]+marks_3[count]+marks_4[count]+marks_5[count];
			float percentage=(total_marks/500)*100;
			file<<"Roll Number : "<<roll_no[count]<<endl;
			file<<"Name : "<<names[count]<<endl;
			file<<"Total Marks : "<<total_marks<<"/500"<<endl;
			file<<"Percentage : "<<percentage<<"%"<<endl;
			file<<"Grade : "<<grade(percentage)<<endl;
			file<<"----------------------"<<endl;
		
	}
	file.close();
}}
void add_student(string names[],int roll_no[],int marks_1[],int marks_2[],int marks_3[],int marks_4[],int marks_5[],int &count){
	
	   if(count>=max_stu){
	   		cout<<"No more data can be added"<<endl;
	   		return;
	   }
	   
		cout<<"Enter student name"<<endl;
		cin.ignore();
		getline(cin,names[count]);
		cout<<"Enter Roll number of student"<<endl;
		cin>>roll_no[count];
		cout<<"Enter marks of students in 1st subject"<<endl;
		cin>>marks_1[count];
		cout<<"Enter marks of students in 2nd subject"<<endl;
		cin>>marks_2[count];
		cout<<"Enter marks of students in 3rd subject"<<endl;
		cin>>marks_3[count];
		cout<<"Enter marks of students in 4th subject"<<endl;
		cin>>marks_4[count];
		cout<<"Enter marks of students in 5th subject"<<endl;
		cin>>marks_5[count];
		save_To_file(names,roll_no,marks_1,marks_2,marks_3,marks_4,marks_5,count);
		count++;

}
void display(){
	fstream file("Student.txt",ios::in);
	if(file.is_open()){
		string line;
		while(getline(file,line)){
			cout<<line<<endl;
		}
	}else{
		cout<<"file not open"<<endl;
	}
	

}
void search_by_roll(fstream &file,int roll){
	file.clear();
	file.seekg(0,ios::beg);
	bool found=false;
	string line;
	while(getline(file,line)){
		if(line.find("Roll Number : "+to_string(roll))!=string::npos){
			found = true;
			cout<<"Student found"<<endl;
			cout<<line<<endl;
			for(int i=0;i<5;i++){
				getline(file,line);
				cout<<line<<endl;
			}
			break;
		}
	}
	if(!found){
		cout<<"Student not found of "<<roll<<" roll number"<<endl;
		return;
	}
	
}
int main(){
	int count=0, option;
	string stu_names[max_stu];
	int roll_no[max_stu];
	int marks_1[max_stu];
	int marks_2[max_stu];
	int marks_3[max_stu];
	int marks_4[max_stu];
	int marks_5[max_stu];

		
	while(true){
	
	do{

	menu();
	cout<<"Enter your choice"<<endl;

	cin>>option;
	
	switch(option){
		case 1:
			add_student(stu_names,roll_no,marks_1,marks_2,marks_3,marks_4,marks_5,count);
			cout<<"Data has been updated sucessfully"<<endl;
			break;
		case 2:
			display();
			break;
		case 3:
			int roll;
			cout<<"Enter Student roll number  "<<endl;
			cin>>roll;
			
			break;
		case 4:
			exit(0);
		
		default:
			cout<<"Invalid choice!"<<endl;
			break;	
		}
	}while(option<1||option>4);
	
	}
	
	return 0;
}