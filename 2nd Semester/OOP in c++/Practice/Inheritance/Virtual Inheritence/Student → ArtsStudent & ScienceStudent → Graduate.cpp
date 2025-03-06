#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;

public:
    void set_name(string n)
    {
        name = n;
    }
    void dispaly_name()
    {
        cout << "Name : " << name << endl;
    }
};
class Art_Student : virtual public Student
{
private:
    string art_subject;

public:
    void set_art_sub(string s)
    {
        art_subject = s;
    }
    void display_art()
    {
        cout << "Art Subject : " << art_subject << endl;
    }
};
class Science_student : virtual public Student
{
private:
    string science_sub;

public:
    void set_science_sub(string s)
    {
        science_sub = s;
    }
    void display_science()
    {
        cout << "Science Subject : " << science_sub << endl;
    }
};
class Graduate : public Art_Student, public Science_student
{
public:
    void display_graduate_details()
    {
        dispaly_name();
        display_art();
        display_science();
    }
};
int main()
{
    Graduate g;

    g.set_name("Awais Iftikhar");
    g.set_art_sub("Urdu");
    g.set_science_sub("Physics");
    
    g.display_graduate_details();

    return 0;
}
