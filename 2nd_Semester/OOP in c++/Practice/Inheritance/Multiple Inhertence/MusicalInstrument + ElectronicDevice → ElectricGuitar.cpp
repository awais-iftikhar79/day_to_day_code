#include <iostream>
#include <string>
using namespace std;

class Musical_Instrument
{
public:
    void play_sound()
    {
        cout << "PLaying musical sound" << endl;
    }
};
class Electronic_Device
{
public:
    void power_on()
    {
        cout << "Device powered on" << endl;
    }
};
class Electric_Guitar : public Musical_Instrument, public Electronic_Device
{
public:
    void strum()
    {
        cout << "Strumming electric guitar" << endl;
    }
};
int main()
{

    Electric_Guitar g;
    g.play_sound();
    g.power_on();
    g.strum();

    return 0;
}