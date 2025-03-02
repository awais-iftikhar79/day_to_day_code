#include <iostream>
#include <string>
using namespace std;

class Electronic_Device
{
protected:
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
class Computer : public Electronic_Device
{
private:
    string processor;

public:
    void set_processor(string p)
    {
        processor = p;
    }
    void display_processor()
    {
        cout << "Processor : " << processor << endl;
    }
};
class laptop : public Computer
{
private:
    float battery_life;

public:
    void set_battery_life(float b)
    {
        battery_life = b;
    }
    void display_battery()
    {
        display_brand();
        display_processor();
        cout << "Battery Life : " << battery_life <<"%"<< endl;
    }
};
int main()
{
    laptop lap;
    lap.set_brand("Dell");
    lap.set_processor("Core i5 6th gen");
    lap.set_battery_life(90.5);
    lap.display_battery();

    return 0;
}