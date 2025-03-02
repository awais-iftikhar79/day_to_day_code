#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
protected:
    string brand;

public:
    void set_brand(string);
    void display_brand()
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
    void display_model()
    {
        cout << "Model : " << model << endl;
    }
};
void Car::set_model(int m)
{
    model = m;
}
class Sport_Car : public Car
{
private:
    int top_speed;

public:
    void set_speed(int);
    void display_top_Speed()
    {
        display_brand();
        display_model();
        cout << "Top Speed is : " << top_speed << " km/h" << endl;
    }
};
void Sport_Car ::set_speed(int s)
{
    top_speed = s;
}
int main()
{
    Sport_Car c1;
    c1.set_brand("Mercedes");
    c1.set_model(2025);
    c1.set_speed(350);
    c1.display_top_Speed();

    return 0;
}