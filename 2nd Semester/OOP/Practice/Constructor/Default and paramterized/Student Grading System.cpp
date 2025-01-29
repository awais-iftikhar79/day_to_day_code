#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int marks_1, marks_2, marks_3;

public:
    Student(string, int, int, int);
    float cal_average();
    void display();
};
Student ::Student(string n, int m1, int m2, int m3)
{
    name = n;
    marks_1 = m1;
    marks_2 = m2;
    marks_3 = m3;
}
float Student ::cal_average()
{
    return ((marks_1 + marks_2 + marks_3) / 3);
}
void Student ::display()
{
    cout << "Your name is : " << name << endl;
    cout << "Your Average marks is : " << cal_average() << endl;
}
int main()
{
    Student s("Awais", 20, 20, 20);
    s.display();
    return 0;
}