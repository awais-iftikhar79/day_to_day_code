#include <iostream>
#include <string>
using namespace std;
class Father
{
private:
    string f_name;

public:
    Father(string fn) : f_name(fn) {}
    void display_father()
    {
        cout << "Father Name : " << f_name << endl;
    }
};
class Mother
{
private:
    string m_name;

public:
    Mother(string mn) : m_name(mn) {}
    void display_mother()
    {
        cout << "Mother Name : " << m_name << endl;
    }
};
class Child : public Father, public Mother
{
private:
    string child_name;

public:
    Child(string fn, string mn, string cn) : Father(fn), Mother(mn)
    {
        child_name = cn;
    }
    void display_child()
    {
        display_father();
        display_mother();
        cout << "Child Name : " << child_name << endl;
    }
};
int main()
{
    Child c("Iftikhar Ahmad", "Shakeela Nayyer", "Awais Iftikhar");
    c.display_child();

    return 0;
}