#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;

public:
    void set_name(string n)
    {
        name = n;
    }
    void display_name()
    {
        cout << "Name : " << name << endl;
    }
};
class Student : public Person
{
private:
    int roll_no;

public:
    void set_roll_no(int r)
    {
        roll_no = r;
    }
    void display_stu_details()
    {
        display_name();
        cout << "Roll # " << roll_no << endl;
    }
};
class Teacher : public Person
{
private:
    string subject;

public:
    void set_subject(string s)
    {
        subject = s;
    }
    void display_teacher_details()
    {
        display_name();
        cout << "Subject : " << subject << endl;
    }
};
int main()
{
    Student s;
    Teacher t;
    s.set_name("Awais Iftikhar");
    s.set_roll_no(2024124);
    t.set_name("Sir Sabir Iqbal");
    t.set_subject("Mathematics");
    cout << "------Student Details-------" << endl;
    s.display_stu_details();
    cout << "------Teacher Details-------" << endl;
    t.display_teacher_details();

    return 0;
}