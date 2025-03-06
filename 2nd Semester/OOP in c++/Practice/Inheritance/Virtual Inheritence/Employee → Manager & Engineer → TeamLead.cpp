#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int id;
    string name;

public:
    void set_details_emp(int i, string n)
    {
        id = i;
        name = n;
    }
    void display_employee()
    {
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
    }
};
class Manager : virtual public Employee
{
private:
    string department;

public:
    void set_depart(string dep)
    {
        department = dep;
    }
    void display_manager()
    {
        cout << "Department : " << department << endl;
    }
};
class Engineer : virtual public Employee
{
private:
    string specialization;

public:
    void set_specialization(string spe)
    {
        specialization = spe;
    }
    void display_specialization()
    {
        cout << "Specialization : " << specialization << endl;
    }
};
class Team_Lead : public Manager, public Engineer
{
private:
    int team_size;

public:
    void set_team_size(int s)
    {
        team_size = s;
    }
    void display_team_size()
    {
        cout << "Team size : " << team_size << endl;
    }
    void display_all_details()
    {
        display_employee();
        display_manager();
        display_specialization();
        display_team_size();
    }
};
int main()
{
    Team_Lead team;

    team.set_details_emp(1001, "Awais Iftikhar");
    team.set_depart("Computer Science");
    team.set_specialization("Artificial Intelligence");
    team.set_team_size(5);

    team.display_all_details();

    return 0;
}