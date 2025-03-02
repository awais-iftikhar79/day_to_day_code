#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    void set_person_details(string, int);
    void display_person()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};
void Person ::set_person_details(string n, int a)
{
    name = n;
    age = a;
}
class Employee : public Person
{
private:
    double salary;

public:
    void set_salary(double);
    void display_salary()
    {
        cout << "Salary : $" << salary << endl;
    }
    double get_Salary()
    {
        return salary;
    }
};
void Employee ::set_salary(double s)
{
    salary = s;
}
class Manager : public Employee
{
private:
    double bonous;

public:
    void set_bonous(double);
    void display_total_earning()
    {
        double total_salary = bonous + get_Salary();
        display_person();
        display_salary();
        cout << "Bonous : $" << bonous << endl;
        cout << "Total Salary (salary+bonous) : $" << total_salary << endl;
    }
};
void Manager ::set_bonous(double b)
{
    bonous = b;
}
int main()
{

    Manager m1;
    m1.set_person_details("Awais Iftikhar ", 19);
    m1.set_salary(5000);
    m1.set_bonous(500);
    m1.display_total_earning();

    return 0;
}