#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string brand;
    int model;

public:
    void set_vehicle(string b, int m)
    {
        brand = b;
        model = m;
    }
    void display_vehicle()
    {
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
    }
};
class Car : virtual public Vehicle
{
private:
    int seats;

public:
    void set_seat(int s)
    {
        seats = s;
    }
    void display_car()
    {
        cout << "Number of Seats : " << seats << endl;
    }
};
class Truck : virtual public Vehicle
{
private:
    int load_capacity;

public:
    void set_load(int l)
    {
        load_capacity = l;
    }
    void display_truck()
    {
        cout << "Load Capacity : " << load_capacity << " kg" << endl;
    }
};
class Hybrid_Vehicle : public Car, public Truck
{
private:
    int battery_capacity;

public:
    void set_battery(int b)
    {
        battery_capacity = b;
    }
    void dispaly_battery()
    {
        cout << "Battery : " << battery_capacity << "%" << endl;
    }
    void display_all_details()
    {
        display_vehicle();
        display_car();
        display_truck();
        dispaly_battery();
    }
};
int main()
{
    Hybrid_Vehicle hb;

    hb.set_vehicle("Haval", 2024);
    hb.set_seat(7);
    hb.set_load(550);
    hb.set_battery(95);

    hb.display_all_details();

    return 0;
}