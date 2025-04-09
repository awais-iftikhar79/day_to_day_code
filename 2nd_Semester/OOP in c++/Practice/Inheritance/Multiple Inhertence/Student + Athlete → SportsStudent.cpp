#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int roll_no;

public:
    void set_stu_details(string, int);
    void display_stu_details()
    {
        cout << "Name : " << name << endl;
        cout << "Roll # " << roll_no << endl;
    }
};
void Student ::set_stu_details(string n, int r)
{
    name = n;
    roll_no = r;
}

class Athlete
{
private:
    string sport;

public:
    void set_sport(string);
    void display_sport()
    {
        cout << "Sport : " << sport << endl;
    }
};
void Athlete ::set_sport(string s)
{
    sport = s;
}

class Sport_Student : public Student, public Athlete
{
public:
    void display_all_details()
    {
        display_stu_details();
        display_sport();
    }
};
int main()
{

    Sport_Student s1;
    s1.set_stu_details("Awais", 2024124);
    s1.set_sport("Cricket");
    s1.display_all_details();

    return 0;
}