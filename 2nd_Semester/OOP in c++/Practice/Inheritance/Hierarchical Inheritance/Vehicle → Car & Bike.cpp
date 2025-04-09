#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string brand;

public:
    void set_brand(string b)
    {
        brand = b;
    }
    void display_brand()
    {
        cout << "Brand : " << brand << endl;
    }
};
class Car : public Vehicle
{
private:
    int seats;

public:
    void set_seats(int s)
    {
        seats = s;
    }
    void display_car()
    {
        display_brand();
        cout << "Number of seats : " << seats << endl;
    }
};
class Bike : public Vehicle
{
private:
    int engine_cc;

public:
    void set_engine(int cc)
    {
        engine_cc = cc;
    }
    void display_bike()
    {
        display_brand();
        cout << "Engine CC  " << engine_cc << endl;
    }
};

int main()
{
    Car c;
    Bike b;
    cout << "------Car Details------" << endl;
    c.set_brand("Toyota");
    c.set_seats(4);
    c.display_car();
    cout << "------Bike Details------" << endl;
    b.set_brand("Honda");
    b.set_engine(100);
    b.display_bike();

    return 0;
}