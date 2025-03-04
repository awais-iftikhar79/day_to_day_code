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

class Employee
{
private:
    double salary;

public:
    void set_salary(double s)
    {
        salary = s;
    }
    void display_salary()
    {
        cout << "Salary : $" << salary << endl;
    }
};

class Manager : public Person, public Employee
{
private:
    string department;

public:
    void set_department(string dep)
    {
        department = dep;
    }
    void dispaly_manager_details()
    {
        display_name();
        display_salary();
        cout << "Department : " << department << endl;
    }
};
int main()
{

    Manager m1;
    m1.set_name("Awais Iftikhar");
    m1.set_salary(7000);
    m1.set_department("AI Engineer");
    m1.dispaly_manager_details();

    return 0;
}