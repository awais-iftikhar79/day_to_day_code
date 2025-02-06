#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string name;
    int modle;
    float price;

public:
    Car();
    Car(string, int, float);
    void display()
    {
        cout << "Brand : " << name << endl;
        cout << "Model : " << modle << endl;
        cout << "Price :$" << price << endl;
    }
};
Car ::Car()
{
    name = "Unknown";
    modle = 0;
    price = 0;
    cout << "Default constructor is called :" << endl;
}
Car ::Car(string n, int m, float p)
{
    name = n;
    modle = m;
    price = p;
    cout << "Parameterized Constructor is called :" << endl;
}
int main()
{
    Car c1,c2("Honda", 2005, 50000);
    c1.display();
    c2.display();

    return 0;
}