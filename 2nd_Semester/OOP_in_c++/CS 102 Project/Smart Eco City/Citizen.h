#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <string>
using namespace std;

class Citizen
{
private:
    string name;
    int transport_mode;
    bool recylce;

public:
    Citizen(string n, int m, bool r) : name(n), transport_mode(m), recylce(r) {}
    string typ_str;
    int get_impact()
    {
        int impact = 0;

        if (transport_mode == 1)
        {
            impact += 5;
            typ_str = "Electric Vehilce";
        }
        else if (transport_mode == 2)
        {
            impact += 10;
            typ_str = "Bicycle";
        }
        else if (transport_mode == 3)
        {
            impact -= 10;
            typ_str = "Non-Electric Vehicle";
        }
        if (recylce)
        {
            impact += 5;
        }
        else
        {
            impact -= 5;
        }
        return impact;
    }
    void citizen_Info()
    {
        cout << "Citizen : " << name << " , Transport Mode : " << typ_str
             << " Recylce " << (recylce ? "Yes" : "No") << endl;
    }
};

void citizen_transport_mode()
{
    cout << "\t1.Electric Vehicle" << endl
         << "\t2.Bicycle" << endl
         << "\t3.Non-Electric Vehicle" << endl;
}

void citizen_recycle_menu()
{
    cout << "\t0.No" << endl
         << "\t1.Yes" << endl;
}

#endif