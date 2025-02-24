#include<iostream>
#include<string>
using namespace std;

class student
{
private:
    string name;
    int age;
public:
    student(){}  //default constructor
    student(string , int);  //perameterized constructor
    student(student& s){   //copy construtor
        name=s.name;
        age=s.age;
    };
    
    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
    
};

student::student(string n,int a)
{
    name=n;
    age=a;
}


int main(){
    student s1("Awais",19);
    s1.display();
    student s2=s1;
    cout<<"Copy of student 1 (copy constructor)"<<endl;
    s2.display();


    return 0;
}