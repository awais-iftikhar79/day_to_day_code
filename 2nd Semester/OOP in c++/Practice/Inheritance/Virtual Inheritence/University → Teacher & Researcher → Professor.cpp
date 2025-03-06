#include <iostream>
#include <string>
using namespace std;
class University
{
    string name;

public:
    void set_uni(string n)
    {
        name = n;
    }
    void display_uni()
    {
        cout << "University Name : " << name << endl;
    }
};
class Teacher : virtual public University
{
private:
    string sub;

public:
    void set_sub(string s)
    {
        sub = s;
    }
    void display_sub()
    {
        cout << "Subject : " << sub << endl;
    }
};
class Researcher : virtual public University
{
private:
    string research_topic;

public:
    void set_topic(string topc)
    {
        research_topic = topc;
    }
    void display_topic()
    {
        cout << "Research Topic : " << research_topic << endl;
    }
};
class Professor : public Teacher, public Researcher
{
public:
    void display_professor_details()
    {
        display_uni();
        display_sub();
        display_topic();
    }
};
int main()
{
    Professor p;

    p.set_uni("Gulam Ishaq Khan Institute");
    p.set_sub("Computer Science");
    p.set_topic("Quantum Computing");

    p.display_professor_details();
    return 0;
}