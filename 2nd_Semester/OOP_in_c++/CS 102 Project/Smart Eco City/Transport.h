#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "City_Object.h"

#include <iostream>
#include <string>
using namespace std;

class Transport : public City_Object
{
private:
    int type;

public:
    Transport(string n, int t) : City_Object(n), type(t) {}

    void operate() override
    {
        string typ_str;
        if (type == 1)
        {
            typ_str = "Electric Vehicle";
            cout << "Transport " << name << " is an Electric Vehicle that increases Eco points" << endl;
        }
        else if (type == 2)
        {
            typ_str = "Non-Electric Vehicle";
            cout << "Transport " << name << " is an Non-Electric Vehicle that Decreases Eco points" << endl;
        }
        else
        {
            cout << "Please Enter correct type " << endl;
            return;
        }
    }
};

void transport_menu()
{
    cout << "1.Electric Vehicle" << endl
         << "2.Non-Electric Vehicle" << endl;
}

#endif