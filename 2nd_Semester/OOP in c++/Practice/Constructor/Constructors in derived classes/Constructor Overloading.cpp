#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string name;
    float salary;

public:
    Employee() : name("unknown"), salary(0)
    {
        cout << "Employee Default Constructor is calling" << endl;
    }
    Employee(string n, float s) : name(n), salary(s)
    {
        cout << "Employee Parameterized Constructor is calling" << endl;
    }
};
class Manager : public Employee
{
private:
    string department;

public:
    Manager() : Employee(), department("general")
    {
        cout << "Manager default constructor is calling" << endl;
    }
    Manager(string n, float s, string d) : Employee(n, s), department(d)
    {
        cout << "Manager Parameterized Constructor is calling" << endl;
    }
};
int main()
{
    Manager m1;
    Manager m2("Awais", 3000, "FCSE");

    return 0;
}