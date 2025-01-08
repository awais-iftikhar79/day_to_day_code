#include <iostream>
#include <string>
using namespace std;
class Student{
private:
    string grade;
    string name;
    string rollno;
public:
    Student(string g,string n,string roll)
    {
        grade = g;
        name = n;
        rollno = roll;

    }
    Student()
    {
        grade = "";
        name = "";
        rollno = "";
    }
    string getName()
    {
        return name;
    }
    string getRollno()
    {
        return rollno;
    }
    string getGrade()
    {
        return grade;
    }
    void setGrade(string g)
    {
        grade = g;
    }
    void setName(string n)
    {
        name =n;
    }
    void setRollno(string r)
    {
        rollno = r;
    }
    void print()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Rollno"<<rollno<<endl;
        cout<<"Grade:"<<grade<<endl;
    }
};

int main()
{
    // string name= "Abdullah";
    // string rollno="123";
    // string grade = "A+";
    // string name2 = "Awais";
    // string rollno2="235";
    // string grade2 = "A+";
    Student s1("A+","Abdullah","123");
    Student s2("A+","Awais","235");
    s1.print();
    s2.print();
}