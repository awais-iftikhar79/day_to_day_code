#include <iostream>
#include <string>
using namespace std;

class student
{
private:
public:
    string name;
    int age;
    char grade;
    void enter()
    {
        cout << "Enter student name " << endl;
        getline(cin, name);
        cout << "Enter age of student " << endl;
        cin >> age;
        cout << "Enter grade of student " << endl;
        cin >> grade;
    }
    void display(void)
    {
        cout << "Student name : " << name << endl;
        cout << "Grade of student : " << grade << endl;
        cout << "Age of student : " << age << endl;
    }
};

int main()
{
    student s1;
    s1.enter();
    s1.display();

    return 0;
}