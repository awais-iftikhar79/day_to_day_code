#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string brand;

public:
    void set_brand(string);
    void display()
    {
        cout << "Brand : " << brand << endl;
    }
};
void Vehicle ::set_brand(string b)
{
    brand = b;
}
class Car : public Vehicle
{
private:
    int model;

public:
    void set_model(int);
    void display_details()
    {
        display();
        cout << "Model : " << model << endl;
    }
};
void Car::set_model(int m)
{
    model = m;
}
int main()
{
    Car c1;
    c1.set_brand("Audi");
    c1.set_model(2025);
    c1.display_details();

    return 0;
}