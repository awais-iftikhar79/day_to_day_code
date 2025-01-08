#include <iostream>
#include <string>
using namespace std;


class Grade{
    private:
    string grade;
    public:
    Grade(int marks)
    {
        if (marks>90)
        {
            grade = "A";
        }
        else if (marks > 80)
        {
            grade = "B";
        }
        else{
            grade="F";
        }
    }
    string getGrade()
    {
        return grade;
    }
};
class Student{
private:
    Grade* grade;
    string name;
    string rollno;
public:
    Student(int M,string n,string roll) 
    {
        grade = new Grade(M);
        name = n;
        rollno = roll;

    }
    Student(string n,string roll,int M)
    {
        name = n;
        rollno = roll;
        grade = new Grade(M);
    }
    Student()
    {
        grade = new Grade(0);
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
        return grade->getGrade();
    }
    // void setGrade(string g)
    // {
    //     grade = g;
    // }
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
        cout<<"Grade:"<<grade->getGrade()<<endl;
    }
    ~Student()
    {
        delete grade;
    }
};



int main()
{
    Student s1(90,"Abdullah","123");
    Student s2(81,"Awais","235");
    s1.print();
    s2.print();
    Student* s3 = new Student(81,"Awais","235");
    Student* s4 = new Student();
    delete s3;
}