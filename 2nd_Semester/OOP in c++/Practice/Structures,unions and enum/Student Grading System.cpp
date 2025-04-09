#include<iostream>
#include<string>
using namespace std;
enum Grade{A=1,B,C,D,E,F};

struct Student
{
    string name ;
    Grade grade;
};

int main(){
    Student s1;
    cout<<"Enter student name "<<endl;
    getline(cin,s1.name);
    int grade_chice;
    cout<<"Enter code for respective grade(1-A,2-B,.....,6-F)"<<endl;
    cin>>grade_chice;
    s1.grade=static_cast<Grade>(grade_chice);

    cout<<"\n Details of students :\n";
    cout<<"Name Of Student : "<<s1.name<<endl;
    cout<<"Grade : ";
    switch (s1.grade)
    {
    case A:
        cout<<"A"<<endl;
        break;
    case B:
        cout<<"B"<<endl;
        break;
    case C:
        cout<<"C"<<endl;
        break;
    case D:
        cout<<"D"<<endl;
        break;
    case E:
        cout<<"E"<<endl;
        break;
    case F:
        cout<<"F"<<endl;
        break;          
    default:
        cout<<"Invalide choice"<<endl;
        break;
    }
    return 0;
} 