#include <iostream>
#include <string>
using namespace std;

class Engine
{
private:
    int horse_power;

public:
    void set_power(int p)
    {
        horse_power = p;
    }
    void dispaly_power()
    {
        cout << "Engine Horse-Power : " << horse_power << endl;
    }
};

class Wheel
{
private:
    int num_wheel;

public:
    void set_wheel(int w)
    {
        num_wheel = w;
    }
    void display_wheel()
    {
        cout << "Number of Wheels : " << num_wheel << endl;
    }
};

class Car : public Engine, public Wheel
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
        dispaly_power();
        display_wheel();
        cout << "Brand : " << brand << endl;
    }
};

int main()
{

    Car c1;
    c1.set_power(750);
    c1.set_wheel(4);
    c1.set_brand("Audi");
    c1.display_brand();

    return 0;
}