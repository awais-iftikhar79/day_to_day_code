
#ifndef UTILTY_H
#define UTILITY_H

#include "City_Object.h"

#include <iostream>
#include <string>
using namespace std;

class Utility : public City_Object
{
private:
    int type;

public:
    Utility(string n, int t) : City_Object(n), type(t) {}

    void operate() override
    {
        string typ_str;
        if (type == 1)
        {
            typ_str = "Solar";
            cout << "Utility " << name << " is a solar plant which increases Eco points" << endl;
        }
        else if (type == 2)
        {
            typ_str = "Wind";
            cout << "Utility " << name << " is a Wind plant which increases Eco points" << endl;
        }
        else if (type == 3)
        {
            typ_str = "Coal";
            cout << "Utility " << name << " is a Coal plant which Decreases Eco points" << endl;
        }
        else
        {
            cout << "Please Enter correct option " << endl;
            return;
        }
    }
};

#endif