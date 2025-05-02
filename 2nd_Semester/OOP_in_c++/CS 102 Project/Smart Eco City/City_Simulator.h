#include "Building.h"
#include "Transport.h"
#include "Utility.h"
#include "Eco_activity.h"
#include "Pollution_Level.h"
#include "Citizen.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class City_Simulator
{
private:
    vector<City_Object *> city_objects;
    vector<Citizen *> citizens;
    Pollution_Level pollution;
    int eco_points = 0;
    string typ_str;

public:
    void add_building(string name, int type)
    {
        Building *building = new Building(name, type);
        city_objects.push_back(building);
        if (type == 1)
        {
            typ_str = "Residential";
        }
        else if (type == 2)
        {
            typ_str = "Commercial";
            eco_points -= 5;
        }
        else if (type == 3)
        {
            eco_points += 15;
            typ_str = "Green Space";
        }
        pollution.update_pollution(typ_str);
        cout << "[+] Building " << name << " added successfuly !" << endl;
    }

    void add_transport(string name, int type)
    {
        Transport *transport = new Transport(name, type);
        city_objects.push_back(transport);
        if (type == 1)
        {
            typ_str = "Electric Vehicle";
            eco_points += 10;
        }
        else if (type == 2)
        {
            typ_str = "Non-Electric Vehicle";
            eco_points -= 10;
        }

        pollution.update_pollution(typ_str);
        cout << "[+] Transport " << name << " added successfuly !" << endl;
    }
};