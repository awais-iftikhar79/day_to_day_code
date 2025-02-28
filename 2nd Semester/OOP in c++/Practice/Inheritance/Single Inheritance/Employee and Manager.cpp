#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    double salary;
    string name;

public:
    // Employee() {}
    // Employee(string n, double s);
    void set_details(string, double);
    double getSalary()
    {
        return salary;
    }
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Salary : $" << salary << endl;
    }
};
void Employee ::set_details(string n, double s)
{
    name = n;
    salary = s;
}
class Manager : public Employee
{
private:
    double bonous;

public:
    void set_bonous(double);
    void display_totalsalary()
    {
        double total_Salary = getSalary() + bonous;
        cout << "Total Salary (+Bonous) : $" << total_Salary << endl;
    }
};
void Manager ::set_bonous(double b)
{
    bonous = b;
}
int main()
{

    Manager m1;
    m1.set_details("Awais ", 50000);
    m1.set_bonous(500);
    m1.display();
    m1.display_totalsalary();

    return 0;
}