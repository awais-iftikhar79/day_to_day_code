#include<iostream>
#include<string>
using namespace std;

struct student
{
    string name;
    int roll_no;
    float marks;
};
void enter_details(student* s){
    cout<<"Enter name of student"<<endl;
    getline(cin,s->name);
    cout<<"Enter roll number of student "<<endl;
    cin>>s->roll_no;
    cout<<"Enter marks of student"<<endl;
    cin>>s->marks;
    cin.ignore();
    cout<<"-------------------"<<endl;
} 
float update_marks(student* s,float increment){
    s->marks += increment;
    return s->marks;
} 
void print_details(student* s){
    cout<<"Name : "<<s->name<<endl;
    cout<<"Roll number : "<<s->roll_no<<endl;
    cout<<"Updated marks : "<<s->marks<<endl;
    cout<<"---------------------"<<endl;
}
int main(){
    student stu[3];
    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter details of student "<<i+1<<endl;
        enter_details(&stu[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        update_marks(&stu[i],5.3);
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"Details of student "<<i+1<<" is : "<<endl;
        print_details(&stu[i]);
    }
    return 0;
}