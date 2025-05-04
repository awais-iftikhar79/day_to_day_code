#ifndef BUILDING_H
#define BUILDING_H

#include "City_Object.h"
#include <iostream>
#include <string>
using namespace std;

class Building : public City_Object
{
private:
    int type;

public:
    Building(string n, int t) : City_Object(n), type(t) {}

    void operate() override
    {
        string typ_str;
        if (type == 1)
        {
            typ_str = "Residential";
            cout << "Building " << name << " is a residential building that increases slightly Eco points " << endl;
        }
        else if (type == 2)
        {
            typ_str = "Commercial";
            cout << "Building " << name << " is a Commercial building that decreases  Eco points " << endl;
        }
        else if (type == 3)
        {
            typ_str = "Green Space";
            cout << "Building " << name << " is a residential building that increases  Eco points " << endl;
        }
        }
};

void building_menu()
{
    cout << "\t1.Residential" << endl
         << "\t2.Commercial" << endl
         << "\t3.Green Space" << endl;
}

#endif
