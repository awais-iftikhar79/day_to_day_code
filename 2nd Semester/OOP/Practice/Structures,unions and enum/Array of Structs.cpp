#include <iostream>
#include <string>
using namespace std;

struct Student
{

    string name;
    int roll_no;
    float marks;
};

int main()
{

    Student stu[5];
    cout << "Enter details of Students " << endl;
    for (int i = 0; i < 5; i++)
    {

        cout << "Enter name of student of " << i + 1 << endl;
        getline(cin, stu[i].name);
        cout << "Enter Roll number of student " << i + 1 << endl;
        cin >> stu[i].roll_no;
        cout << "Enter marks of student " << i + 1 << endl;
        cin >> stu[i].marks;
        cin.ignore();
    }
    cout<<endl;
    
    cout << "Details of students are " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Name : " << stu[i].name << endl;
        cout << "Roll number : " << stu[i].roll_no << endl;
        cout << "Marks : " << stu[i].marks << endl;
        cout << endl;
    }

    return 0;
}