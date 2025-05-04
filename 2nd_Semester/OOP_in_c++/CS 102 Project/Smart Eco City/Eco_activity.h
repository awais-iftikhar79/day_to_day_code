#ifndef ECO_ACTIVITY_H
#define ECO_ACTIVITY_H

#include "City_Object.h"

#include <iostream>
#include <string>
using namespace std;

class Eco_Activity : public City_Object
{
private:
    int type;

public:
    Eco_Activity(string n, int t) : City_Object(n), type(t) {}

    void operate() override
    {
        string typ_str;
        if (type == 1)
        {
            typ_str = "Tree Planting";
            cout << "Eco Activity " << typ_str << " increases Eco points" << endl;
        }
        else if (type == 2)
        {
            typ_str = "Recycling";
            cout << "Eco Activity " << typ_str << " increases Eco points" << endl;
        }
        }
};

void eco_activity_menu()
{
    cout << "\t1.Tree Planting" << endl
         << "\t2.Reccling" << endl;
}
#endif