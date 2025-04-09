#include <iostream>
#include <string>
using namespace std;

enum Status
{
    Active = 1,
    Inactive,
    Retired
};

struct Details
{
    int ID;
    string department;
};

struct Empolyee
{
    string name;
    int age;
    float salary;
    Status sta;
    Details De;
};

int main()
{
    Empolyee e;
    cout << "Enter name of empolyee" << endl;
    getline(cin, e.name);
    cout << "Enter age of employee" << endl;
    cin >> e.age;
    cout << "Enter salary of employee" << endl;
    cin >> e.salary;
    int check_status;
    cout << "Enter status (1-Active,2-Inactive,3-Retired)" << endl;
    cin >> check_status;
    e.sta = static_cast<Status>(check_status);
    int detail_chioce;
    cout << "Enter detail choice (1-ID,2-Department)" << endl;
    cin >> detail_chioce;
    if (detail_chioce == 1)
    {
        cout << "Enter Employee ID" << endl;
        cin >> e.De.ID;
    }
    else if (detail_chioce == 2)
    {
        cin.ignore();
        cout << "Enter department of Employee" << endl;
        getline(cin, e.De.department);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    cout << "\nDetails of Employee" << endl;
    cout << "Name : " << e.name << endl;
    cout << "Age : " << e.age << endl;
    cout << "Salary : Rs." << e.salary << endl;
    cout << "Status : ";
    switch (e.sta)
    {
    case Active:
        cout << "Active" << endl;
        break;
    case Inactive:
        cout << "Inactive" << endl;
        break;
    case Retired:
        cout << "Retired" << endl;
        break;
    default:
        cout << "Invalid Status" << endl;
        break;
    }
    if (detail_chioce == 1)
    {
        cout << "ID : " << e.De.ID;
    }
    else if (detail_chioce == 2)
    {
        cout << "Department : " << e.De.department;
    }
    return 0;
}