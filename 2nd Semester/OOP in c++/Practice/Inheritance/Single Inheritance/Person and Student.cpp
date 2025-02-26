#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    void set_details(string n, int a)
    {
        name = n;
        age = a;
    }
    void display_details()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};
class Student : public Person
{
private:
    int roll_no;

public:
    void set_roll_no(int r)
    {
        roll_no = r;
    }
    void display_roll_no()
    {
        cout << "Roll number : " << roll_no << endl;
    }
};
int main()
{
    Student s1;
    s1.set_details("Awais", 19);
    s1.set_roll_no(2024124);
    s1.display_details();
    s1.display_roll_no();

    return 0;
}