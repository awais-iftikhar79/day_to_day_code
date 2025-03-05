#include <iostream>
#include <string>
using namespace std;
class Employee
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
class Engineer : public Employee
{
private:
    string specialization;

public:
    void set_specialization(string s)
    {
        specialization = s;
    }
    void dispaly_engineer()
    {
        cout << "------Engineer------" << endl;
        display_name();
        cout << "Specialization : " << specialization << endl;
    }
};
class Manager : public Employee
{
private:
    string department;

public:
    void set_department(string d)
    {
        department = d;
    }
    void dispaly_manager()
    {
        cout << "------Manager------" << endl;
        display_name();
        cout << "Department : " << department << endl;
    }
};
int main()
{

    Engineer e;
    Manager m;

    e.set_name("Awais IFtikhar");
    e.set_specialization("Artificial Intelligence");
    e.dispaly_engineer();

    m.set_name("Amjad Akhtar Syal");
    m.set_department("Punjab College");
    m.dispaly_manager();

    return 0;
}