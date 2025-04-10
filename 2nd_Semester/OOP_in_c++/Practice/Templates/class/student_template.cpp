#include <iostream>
#include <string>
using namespace std;

template <class T>
class Student
{
private:
    string name;
    T id;

public:
    Student(string n, T i) : name(n), id(i) {}
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
    }
};
int main()
{
    Student<int> s1("Awais Iftikhar", 2024124);
    s1.display();

    Student<string> s2("Abid Kazmi", "Smart card");
    s2.display();

    return 0;
}