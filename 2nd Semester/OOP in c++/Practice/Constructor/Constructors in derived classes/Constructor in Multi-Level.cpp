#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
private:
    string brand;

public:
    Vehicle(string b) : brand(b) {}
    void print_vehcle()
    {
        cout << "Brand : " << brand << endl;
    }
};
class Car : public Vehicle
{
private:
    string model;

public:
    Car(string b, string m) : Vehicle(b)
    {
        model = m;
    }
    void print_car()
    {
        cout << "Model : " << model << endl;
    }
};
class Electric_Car : public Car
{
private:
    int battery_capacity;

public:
    Electric_Car(string b, string m, int bat) : Car(b, m)
    {
        battery_capacity = bat;
    }
    void print_electric()
    {
        print_vehcle();
        print_car();
        cout << "Battery : " << battery_capacity << endl;
    }
};
int main()
{
    Electric_Car e("Tesla", "Models", 100);
    e.print_electric();
    return 0;
}