#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    virtual void show()
    {
        cout << "This is a person" << endl;
    }
};
class Employee : virtual Person
{
public:
    void show()
    {
        cout << "This is an Employee" << endl;
    }
};
class Student : virtual public Person
{
public:
    void show()
    {
        cout << "This is an Student" << endl;
    }
};
class Intern : public Employee, public Student
{
public:
    void show()
    {
        Employee::show();
    }
};
int main()
{
    Intern intern;
    intern.show();
    
    return 0;
}