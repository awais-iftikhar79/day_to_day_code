#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string brand;
    int model;

public:
    Car() {}
    Car(string, int);
    ~Car()
    {
        cout << "Destructor is calling" << endl;
    }
};
Car ::Car(string b, int m)
{
    brand = b;
    model = m;
}
int main()
{
    cout << "Creating 1sst object" << endl;
    Car c1("civic", 2002);
    cout << "Entering into  a block" << endl;
    {
        Car c2("toyota", 2020);
        cout << "Exiting this block" << endl;
    }
    cout << "Back to main" << endl;

    return 0;
}