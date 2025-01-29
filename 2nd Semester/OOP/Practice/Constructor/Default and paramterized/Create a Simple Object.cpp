#include <iostream>
#include <string>
using namespace std;

class person
{
private:
    string name;
    int age;

public:
//Default Constructor 
    person()
    {
        name = "Unknown";
        age = 0;
        cout << "Default constructor is called :" << endl;
    }
    void display()
    {
        cout << "My name is : " << name << " \nMy age is : " << age << endl;
    }
};
int main()
{
    person p;
    p.display();
    return 0;
}