#ifndef CITY_SIMULATOR_H
#define CITY_SIMULATOR_H

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
        cout << "\033[1;32m[+] Building " << name << " added successfuly !\033[0m" << endl; // Green
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
        cout << "\033[1;32m[+] Transport " << name << " added successfuly !\033[0m" << endl; // Green
    }

    void add_utility(string name, int type)
    {
        Utility *utility = new Utility(name, type);
        city_objects.push_back(utility);

        if (type == 1)
        {
            eco_points += 10;
            typ_str = "Solar";
        }
        else if (type == 2)
        {
            eco_points += 15;
            typ_str = "Wind";
        }
        else if (type == 3)
        {
            eco_points -= 15;
            typ_str = "Coal";
        }
        pollution.update_pollution(typ_str);
        cout << "\033[1;32m[+] Utility " << name << " added successfuly !\033[0m" << endl;
    }

    void add_eco_activity(string name, int type)
    {
        Eco_Activity *eco_activity = new Eco_Activity(name, type);
        city_objects.push_back(eco_activity);

        if (type == 1)
        {
            eco_points += 5;
            typ_str = "Tree Planting";
        }
        else if (type == 2)
        {
            eco_points += 10;
            typ_str = "Recycling";
        }
        pollution.update_pollution(typ_str);
        cout << "\033[1;32m[+] Eco Activity " << name << " added successfuly !\033[0m" << endl;
    }

    void add_citizen(string name, int transport_mode, bool recycle)
    {
        Citizen *citizen = new Citizen(name, transport_mode, recycle);
        citizens.push_back(citizen);

        eco_points += citizen->get_impact();

        if (transport_mode == 1)
        {
            typ_str = "Electric Vehicle";
        }
        else if (transport_mode == 2)
        {
            typ_str = "Bicycle";
        }
        else if (transport_mode == 3)
        {
            typ_str = "Non-Electric Vehicle";
        }

        pollution.update_pollution(typ_str);

        cout << "\033[1;32m[+] Citizen " << name << " added successfuly !\033[0m" << endl;
    }

    void show_eco_points()
    {
        cout << "Current Eco Points : " << eco_points << endl;
        pollution.report();
    }

    void show_all_city()
    {
        for (auto obj : city_objects)
        {
            obj->operate();
        }

        for (auto c : citizens)
        {
            c->citizen_Info();
        }
    }

    ~City_Simulator()
    {
        for (auto obj : city_objects)
        {
            delete obj;
        }

        for (auto c : citizens)
        {
            delete c;
        }
    }
};

#endif