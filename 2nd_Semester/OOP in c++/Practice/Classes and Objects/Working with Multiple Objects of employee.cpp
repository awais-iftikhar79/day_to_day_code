#include <iostream>
#include <string>
using namespace std;
class employee
{
private:
    string name;
    int id;
    float salary;

public:
    void set_details()
    {
        cout << "Enter name of Employee" << endl;
        getline(cin, name);
        cout << "Enter ID " << endl;
        cin >> id;
        cout << "Enter Employee salary " << endl;
        cin >> salary;
        cin.ignore();
    }
    void print()
    {
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
        cout << "Salary : $" << salary << endl;
    }
};
int main()
{
    employee emp[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details of " << i + 1 << " employee" << endl;
        emp[i].set_details();
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "\nDetails of " << i + 1 << " employee are :\n\n";
        emp[i].print();
    }

    return 0;
}