#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    void display_person()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};
class Student : public Person
{
private:
    string grade;

public:
    Student(string n, int a, string g) : Person(n, a)
    {
        grade = g;
    }
    void display_Stu()
    {
        display_person();
        cout << "Grade : " << grade << endl;
    }
};
int main()
{
    Student s("Awais", 19, "B+");
    s.display_Stu();
    return 0;
}